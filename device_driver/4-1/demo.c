#include <linux/module.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "./stm32mp1xx_gpio.h"
#include "./stm32mp1xx_rcc.h"

#define CDEV_NAME "democdev"
#define COUNT 3

char kbuf[8];
struct led_dev {
    gpio_t *paddr;
    gpio_t *vaddr;
    int pin;
};
gpio_t *base;
int pin;

struct led_dev ledarr[3]={
    {
        .paddr=(gpio_t *)0x50006000,
        .pin=10,
    },
    {
        .paddr=(gpio_t *)0x50007000,
        .pin=10
    },
    {
        .paddr=(gpio_t *)0x50006000,
        .pin=8,
    },
};

dev_t devno;
dev_t current_devno;
int ret;
int i;
char kernel_buf[64];
char nodbuf[8];
gpio_t *vgpioe;
gpio_t *vgpiof;
rcc_t *vrcc;
struct class *scls = NULL;
struct device *sdev = NULL;
int major_device_number;
int minor_device_number;

void led_init(void){
    vrcc->MP_AHB4ENSETR |= (0x1<<4);
    vrcc->MP_AHB4ENSETR |= (0x1<<5);
}

int demo_open(struct inode *inode, struct file *file)
{
	printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    current_devno = inode->i_rdev;
    minor_device_number=MINOR(current_devno);
    file->private_data=(void *)minor_device_number;
    base=ledarr[(int)file->private_data].vaddr;
    pin=ledarr[(int)file->private_data].pin;
    base->MODER &= ~(3<<(pin<<1));
    base->MODER |= (1<<(pin<<1));
	return 0;
}
ssize_t demo_write(struct file *file, const char __user *ubuf, size_t size, loff_t *pos){
    int ret;
    int minor;
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    minor=(int)file->private_data;
    base=ledarr[minor].vaddr;
    if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);
	}
	ret = copy_from_user(kbuf, ubuf, size);
	if(ret != 0)
	{
		printk("copy_from_user error!");
		return -EIO;
	}

	printk("kbuf[0] = %c\n", kbuf[0]);

    if (kbuf[0] == '1')
	{
		base->ODR |= (1 << ledarr[minor].pin);
	}

	if (kbuf[0] == '0')
	{
		base->ODR &= ~(1 << ledarr[minor].pin);
	}

	return size;

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
    .write=demo_write,
    .release=demo_close,
};

static int __init demo_init(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    for(i=0;i<ARRAY_SIZE(ledarr);i++){
        ledarr[i].vaddr=ioremap(ledarr[i].paddr,sizeof(gpio_t));
        if(!ledarr[i].vaddr){
            printk("ledarr[%d] ioremap error\n",i);
            cdev_del(&democdev);
            unregister_chrdev_region(devno,COUNT);
            return -ENOMEM;
        }
    }
    vrcc=ioremap((phys_addr_t)RCC,4);
    if(NULL==vrcc){
        printk("rcc ioremap error\n");
        cdev_del(&democdev);
        unregister_chrdev_region(devno,COUNT);
        return -1;
    }
    alloc_chrdev_region(&devno,0,COUNT,CDEV_NAME);
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
    scls=class_create(THIS_MODULE,CDEV_NAME);
    if(IS_ERR(scls)){
        printk("class_create error\n");
        class_destroy(scls);
        iounmap(vgpioe);
        iounmap(vgpiof);
        iounmap(vrcc);
        cdev_del(&democdev);
        unregister_chrdev_region(devno,COUNT);
        return PTR_ERR(scls);
    }
    for(i=0;i<COUNT;i++){
        sprintf(nodbuf,"demo%d",i+1);
        sdev=device_create(scls,NULL,devno+i,NULL,nodbuf);
        if(IS_ERR(sdev)){
            printk("device_create error\n");
            class_destroy(scls);
            iounmap(vgpioe);
            iounmap(vgpiof);
            iounmap(vrcc);
            cdev_del(&democdev);
            unregister_chrdev_region(devno,COUNT);
            return PTR_ERR(sdev);
        }
    }
    led_init();
    return 0;
}
static void __exit  demo_exit(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    device_destroy(scls, devno);
	class_destroy(scls);
    iounmap(vgpioe);
    iounmap(vgpiof);
    iounmap(vrcc);
    //从内核中删除cdev对象
    cdev_del(&democdev);
    //释放设备号
    unregister_chrdev_region(devno,COUNT);
    return ;
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("Dual BSD/GPL");