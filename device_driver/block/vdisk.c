#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>
#include <linux/vmalloc.h>
#include <linux/blk-mq.h>


#define VDSK_MINORS		4
#define VDSK_HEADS		4
#define	VDSK_SECTORS		16
#define VDSK_CYLINDERS		256
#define VDSK_SECTOR_SIZE	512
#define VDSK_SECTOR_TOTAL	(VDSK_HEADS * VDSK_SECTORS * VDSK_CYLINDERS)
#define VDSK_SIZE		(VDSK_SECTOR_TOTAL * VDSK_SECTOR_SIZE)

static int vdsk_major = 0;
static char vdsk_name[] = "vdsk";

struct vdsk_dev
{
	int size;
	u8 *data;
	spinlock_t lock;
	struct gendisk *gd;
	struct request_queue *queue;
	struct blk_mq_tag_set vdsk_tag_set;
};

static struct vdsk_dev *vdsk = NULL;

static int vdsk_open(struct block_device *bdev, fmode_t mode)
{
	printk("%s\n", __func__);
	return 0;
}

static void vdsk_release(struct gendisk *gd, fmode_t mode)
{
	printk("%s\n", __func__);
}

static int vdsk_ioctl(struct block_device *bdev, fmode_t mode, unsigned cmd, unsigned long arg)
{
	return 0;
}

static int vdsk_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
	geo->cylinders = VDSK_CYLINDERS;
	geo->heads = VDSK_HEADS;
	geo->sectors = VDSK_SECTORS;
	geo->start = 0;
	return 0;
}

blk_status_t vdsk_queue_rq(struct blk_mq_hw_ctx * ctx, const struct blk_mq_queue_data * q)
{
	struct request* rq = q->rq;
	struct bio_vec bvec;
	struct req_iterator iter;
	loff_t pos = blk_rq_pos(rq) * VDSK_SECTOR_SIZE;

	blk_mq_start_request(rq);
	rq_for_each_segment(bvec, rq, iter)
	{
		unsigned long len = bvec.bv_len;

		void* buffer = page_address(bvec.bv_page) + bvec.bv_offset;

		if (pos + len > VDSK_SECTOR_TOTAL)
		{
			len = VDSK_SECTOR_TOTAL - pos;
		}

		if (rq_data_dir(rq) == WRITE)
		{
			memcpy(vdsk->data + pos, buffer, len);
		}
		else
		{
			memcpy(buffer, vdsk->data + pos, len);
		}
		pos += len;
	}

	blk_mq_end_request(rq, BLK_STS_OK);

	return BLK_STS_OK;
}

static const struct blk_mq_ops vdsk_mq_ops = {
	.queue_rq = vdsk_queue_rq,
};

/*
static void vdsk_request(struct request_queue *q)
{
	struct vdsk_dev *vdsk;
	struct request *req;
	struct bio *bio;
	struct bio_vec bvec;
	struct bvec_iter iter;
	unsigned long offset;
	unsigned long nbytes;
	char *buffer;

	vdsk = q->queuedata;
	req = blk_fetch_request(q);
	while (req != NULL) {
		__rq_for_each_bio(bio, req) {
			bio_for_each_segment(bvec, bio, iter) {
				buffer = __bio_kmap_atomic(bio, iter);
				offset = iter.bi_sector * VDSK_SECTOR_SIZE;
				nbytes = bvec.bv_len;

				if ((offset + nbytes) > get_capacity(vdsk->gd) * VDSK_SECTOR_SIZE)
					return;

				if (bio_data_dir(bio) == WRITE)
					memcpy(vdsk->data + offset, buffer, nbytes);
				else
					memcpy(buffer, vdsk->data + offset, nbytes);

				__bio_kunmap_atomic(bio);
			}
		}

		if (!__blk_end_request_cur(req, 0))
			req = blk_fetch_request(q);
	}
}
*/

static struct block_device_operations vdsk_fops = {
	.owner = THIS_MODULE,
	.open = vdsk_open,
	.release = vdsk_release,
	.ioctl = vdsk_ioctl,
	.getgeo = vdsk_getgeo,
};

static int __init vdsk_init(void)
{
	vdsk_major = register_blkdev(vdsk_major, vdsk_name);
	if (vdsk_major <= 0)
		return -EBUSY;

	vdsk = kzalloc(sizeof(struct vdsk_dev), GFP_KERNEL);
	if (!vdsk)
		goto unreg_dev;

	vdsk->size = VDSK_SIZE;
	vdsk->data = vmalloc(vdsk->size);
	if (!vdsk->data)
		goto free_dev;

	spin_lock_init(&vdsk->lock);
	//vdsk->queue = blk_init_queue(vdsk_request, &vdsk->lock);
	vdsk->queue = blk_mq_init_sq_queue(&vdsk->vdsk_tag_set, &vdsk_mq_ops,
			2, BLK_MQ_F_SHOULD_MERGE);
	//blk_queue_logical_block_size(vdsk->queue, VDSK_SECTOR_SIZE);
	//vdsk->queue->queuedata = vdsk;

	vdsk->gd = alloc_disk(VDSK_MINORS);
	if (!vdsk->gd)
		goto free_data;

	vdsk->gd->major = vdsk_major;
	vdsk->gd->first_minor = 0;
	vdsk->gd->fops = &vdsk_fops;
	vdsk->gd->queue = vdsk->queue;
	vdsk->gd->private_data = vdsk;
	snprintf(vdsk->gd->disk_name, 32, "vdsk%c", 'a');
	set_capacity(vdsk->gd, VDSK_SECTOR_TOTAL);
	add_disk(vdsk->gd);
	return 0;

free_data:
	blk_cleanup_queue(vdsk->queue);
	vfree(vdsk->data);
free_dev:
	kfree(vdsk);
unreg_dev:
	unregister_blkdev(vdsk_major, vdsk_name);
	return -ENOMEM;
}

static void __exit vdsk_exit(void)
{
	del_gendisk(vdsk->gd);
	put_disk(vdsk->gd);
	blk_cleanup_queue(vdsk->queue);
	vfree(vdsk->data);
	kfree(vdsk);
	unregister_blkdev(vdsk_major, vdsk_name);
}

module_init(vdsk_init);
module_exit(vdsk_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Jiang <jiangxg@farsight.com.cn>");
MODULE_DESCRIPTION("This is an example for Linux block device driver");
