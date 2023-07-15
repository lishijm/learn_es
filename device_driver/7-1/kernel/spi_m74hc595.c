#include <linux/init.h>
#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/spi/spi-mem.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <asm/io.h>
#include <linux/of_device.h>


#define CMD_WRITE_DIGITAL _IOW('S',0x00,int)
//#define CMD_WRITE_DIGITAL 0xab

char code[] = {
	0x3f,/*display 0*/
	0x06,/*display 1*/
	0x5b,/*display 2*/
	0x4f,/*display 3*/
	0x66,/*display 4*/
	0x6d,/*display 5*/
	0x7d,/*display 6*/
	0x07,/*display 7*/
	0x7f,/*display 8*/
	0x6f /*display 9*/
};

struct m74hc595_device{
	dev_t devno;
	struct cdev cdev;
	struct class *cls;
	struct device *dev;
	struct spi_device *spi;
};


/* This function handles open for the character device */
static int m74hc595_chrdev_open(struct inode *inode, struct file *file)
{
	struct m74hc595_device *m74hc595 = container_of(inode->i_cdev,struct m74hc595_device,cdev);
	file->private_data = m74hc595;
	printk("m74hc595 chrdev open success!\n");
	return 0;
}

int m74hc595_spi_transfer(struct spi_device *spi,unsigned short pos_code)
{
	int error;
	struct spi_message message;
	struct spi_transfer xfer[1] = {0};
	unsigned char tx[2]  = {0};


	tx[0] = pos_code & 0xff;
	printk("tx0 = %d \n",tx[0]);
	tx[1] = code[pos_code >> 8];
	printk("tx1 = %#x \n",tx[1]);

	spi_message_init(&message);
	xfer[0].tx_buf = (const void *)&tx;
	xfer[0].len = sizeof(tx)/sizeof(tx[0]);
	spi_message_add_tail(&xfer[0], &message);
	
	error = spi_sync(spi, &message);
	if (unlikely(error)) {
		dev_err(&spi->dev, "SPI read error: %d\n", error);
		return error;
	}

	return 0;
}

static long m74hc595_chrdev_ioctl(struct file *file, unsigned int cmd,unsigned long arg)
{
	int ret = 0;
	unsigned short pos_code;
	struct m74hc595_device *m74hc595 = file->private_data;
	
	switch(cmd){
		case CMD_WRITE_DIGITAL:
			if(copy_from_user(&pos_code,(void *)arg,sizeof(pos_code)) != 0)
				printk("copy error  \n");
//			printk("pos_code: %d\n",pos_code);
			ret = m74hc595_spi_transfer(m74hc595->spi,pos_code); 
			break;
	
		default:
			printk("unKnown cmd!\n");
			break;
	}
	
	return ret;
}

static int m74hc595_chrdev_release(struct inode *inode, struct file *file)
{
	printk("m74hc595 chrdev release success!\n");

	return 0;
}


/* File operations struct for character device */
static const struct file_operations m74hc595_fops = {
	.owner		     = THIS_MODULE,
	.open		     = m74hc595_chrdev_open,
	.unlocked_ioctl	 = m74hc595_chrdev_ioctl,
	.release	     = m74hc595_chrdev_release,
};


int register_m74hc595_chrdev(struct m74hc595_device *m74hc595)
{
	int retval;

	cdev_init(&m74hc595->cdev,&m74hc595_fops);

	retval = alloc_chrdev_region(&m74hc595->devno,0,1,"m74hc595");
	if(retval < 0){
		printk("Fail to alloc chrdev region\n");
		goto err_alloc_chrdev_region;
	}
	
	retval = cdev_add(&m74hc595->cdev,m74hc595->devno,1);
	if(retval){
		printk("Fail to cdev add\n");

		goto err_cdev_add;
	}

	m74hc595->cls = class_create(THIS_MODULE, "m74hc595");
	if (IS_ERR(m74hc595->cls)){
		printk("Fail to class create\n");
		retval = PTR_ERR(m74hc595->cls);
		goto err_class_create;
	}
	
	m74hc595->dev = device_create(m74hc595->cls,NULL,m74hc595->devno,NULL,"m74hc595_device");
	if (IS_ERR(m74hc595->dev)) {
		printk("Fail to device create\n");
		retval = PTR_ERR(m74hc595->dev);
		goto err_device_create;
	}

	return 0;
	
err_device_create:
	class_destroy(m74hc595->cls);
	
err_class_create:
	cdev_del(&m74hc595->cdev);

err_cdev_add:
	unregister_chrdev_region(m74hc595->devno,1);

err_alloc_chrdev_region:
	return retval;	
}

static int m74hc595_spi_probe(struct spi_device *spi)
{
	int ret;
	struct m74hc595_device *m74hc595;
	
	printk("m74hc595 probe success\n");
	m74hc595 = devm_kmalloc(&spi->dev,sizeof(*m74hc595),GFP_KERNEL);
	if(!m74hc595){
		printk("Fail to kmalloc\n");
		return -ENOMEM;
	}
	spi_set_drvdata(spi,m74hc595);

	m74hc595->spi = spi;

	ret = register_m74hc595_chrdev(m74hc595);
	if(ret < 0){
		printk("Fail to register m74hc595 chrdev\n");
		return ret;
	}
	
	return 0;
}

static int m74hc595_spi_remove(struct spi_device *spi)
{
	struct m74hc595_device *m74hc595= spi_get_drvdata(spi);
	
	printk("m74hc595 remove success\n");
	device_destroy(m74hc595->cls,m74hc595->devno);
	class_destroy(m74hc595->cls);
	cdev_del(&m74hc595->cdev);
	unregister_chrdev_region(m74hc595->devno,1);
	
	return 0;
}

static const struct spi_device_id m74hc595_spi_id[] = {
	{"m74hc595", 0},
	{}
};

MODULE_DEVICE_TABLE(spi, m74hc595_spi_id);

static const struct of_device_id m74hc595_of_ids[] = {
	{.compatible = "m74hc595", },
	{},
};
MODULE_DEVICE_TABLE(of, m74hc595_of_ids);

static struct spi_driver m74hc595_spi_driver = {
	.driver = {
		.name	= "m74hc595_spi",
		.of_match_table = of_match_ptr(m74hc595_of_ids),
	},
	.probe		= m74hc595_spi_probe,
	.remove		= m74hc595_spi_remove,
	.id_table	= m74hc595_spi_id,
};
module_spi_driver(m74hc595_spi_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("M74HC595 SPI driver");
