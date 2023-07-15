#include <linux/module.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define CDEV_NAME "democdev"
#define COUNT 1
#if 0
int major_device_number=240;
int minor_device_number=0;
#endif
dev_t devno;
int ret;
char kernel_buf[64];

int demo_open(struct inode *inode, struct file *file)
{
	printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
	return 0;
}

ssize_t demo_read(struct file *file, char __user *ubuf, size_t size, loff_t *pos)
{
	printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    if(size>sizeof(kernel_buf)){
        size=sizeof(kernel_buf);
    }
    ret=copy_to_user(ubuf,kernel_buf,size);
    if(ret!=0){
        printk("copy_to_user error\n");
        return -EIO;
    }
	return 0;
}

ssize_t demo_write(struct file *file, const char __user *ubuf, size_t size, loff_t *pos)
{
	printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    if(size>sizeof(kernel_buf)){
        size=sizeof(kernel_buf);
    }
    ret=copy_from_user(kernel_buf,ubuf,size);
    if(ret!=0){
        printk("copy_from_user error\n");
        return -EIO;
    }
	return 0;
}
int demo_close(struct inode *inode, struct file *file)
{
	printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
	return 0;
}

//实例化cedv
struct cdev democdev;
struct file_operations fops=
{
    .open=demo_open,
    .read=demo_read,
    .write=demo_write,
    .release=demo_close,
};

static int __init demo_init(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    alloc_chrdev_region(&devno,0,COUNT,CDEV_NAME);
#if 0
    devno=MKDEV(major_device_number,minor_device_number);
    //静态申请设备号
    register_chrdev_region(devno,COUNT,CDEV_NAME);
    if(ret!=0){
        printk("register_chrdev_region error\n");
        return -1;
    }
#endif
    //对cdev对象初始化并和fops进行关联
    democdev.dev=devno;
    democdev.count=COUNT;
    cdev_init(&democdev,&fops);
    //添加cdev对象到内核
    ret=cdev_add(&democdev,devno,COUNT);
    if(ret!=0){
        printk("cdev_add error\n");
        //释放设备号
        unregister_chrdev_region(devno,COUNT);
        return -1;
    }
    return 0;
}
static void __exit  demo_exit(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    //从内核中删除cdev对象
    cdev_del(&democdev);
    //释放设备号
    unregister_chrdev_region(devno,COUNT);
    return ;
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("Dual BSD/GPL");