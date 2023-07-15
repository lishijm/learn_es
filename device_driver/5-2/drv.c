#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/ide.h>
#include <linux/of.h>

#include "./stm32mp1xx_gpio.h"

#define LED_MAJOR 240
#define RCC_MP_AHB4ENSETR 0x50000a28

unsigned int *rccbase;

struct sled_info{
    gpio_t *base;
    int pin;
    struct cdev cdev;
};

int led_open(struct inode * inodp,struct file *filp){
    struct sled_info * ledinfo=container_of (inodp->i_cdev,struct sled_info,cdev);
    filp->private_data=ledinfo;
    printk(KERN_INFO"lde_open\n");
    printk(KERN_INFO"base: %p,pin:%d\n",ledinfo->base,ledinfo->pin);
    return 0;
}

int led_release(struct inode *inodp,struct file *filp){
    return 0;
}

ssize_t led_write(struct file * filp, const char __user * buf, size_t size, loff_t * pos){
    struct sled_info *ledinfo=(struct sled_info *)filp->private_data;
    char cmd;
    printk(KERN_INFO "sled_write\n");
    get_user(cmd,buf);
    printk(KERN_INFO"cmd:%c\n",cmd);
    if(cmd=='1'){
        printk("led on bfore\n");
        printk("%d\n",ledinfo->pin);
        ledinfo->base->ODR |= (1<<ledinfo->pin);
        printk(KERN_INFO"led on");
    }
    else if(cmd=='0'){
        ledinfo->base->ODR &= ~(1<<ledinfo->pin);
        printk(KERN_INFO"led off");
    }

    return size;
}

static struct file_operations fops={
    .owner=THIS_MODULE,
    .open=led_open,
    .release=led_release,
    .write=led_write,
};

int drv_probe(struct platform_device *dev){
    struct sled_info * ledinfo;
    struct resource *res;
    dev_t devno;
    int ret;
    of_property_read_u32(dev->dev.of_node,"id",&(dev->id));
    devno=MKDEV(LED_MAJOR,dev->id);
    ret=register_chrdev_region(devno,1,"ex_led");
    if(ret){
        printk(KERN_ERR"regiseter_chardev_region failed\n");
        return ret;
    }
    ledinfo=kmalloc(sizeof(struct sled_info),GFP_KERNEL);
    if(!ledinfo){
        unregister_chrdev_region(devno,1);
        printk("malloc error!!\n");
        return -ENOMEM;
    }
    cdev_init(&(ledinfo->cdev),&fops);
    ledinfo->cdev.owner=THIS_MODULE;
    ret=cdev_add(&(ledinfo->cdev),devno,1);
    if(ret){
        unregister_chrdev_region(devno,1);
        kfree(ledinfo);
        return ret;
    }
    res=platform_get_resource(dev,IORESOURCE_MEM,0);
    if(res==NULL){
        unregister_chrdev_region(devno,1);
        kfree(ledinfo);
        cdev_del(&(ledinfo->cdev));
        return -ENOENT;
    }

    ledinfo->base=ioremap(res->start,resource_size(res));
    if(ledinfo->base==NULL){
        unregister_chrdev_region(devno,1);
        kfree(ledinfo);
        cdev_del(&(ledinfo->cdev));
        return -ENOENT;
    }

    of_property_read_u32(dev->dev.of_node,"pin",&(ledinfo->pin));
    printk("%d\n",ledinfo->pin);
    ledinfo->base->MODER &= ~(3<<(ledinfo->pin<<1));
    ledinfo->base->MODER |= (1<<(ledinfo->pin<<1));
    
    //保存局部变量
    platform_set_drvdata(dev,ledinfo);

    printk(KERN_INFO"led%d initalized\n",dev->id);

    return 0;
}

int drv_remove(struct platform_device * dev){
    struct sled_info *ledinfo=platform_get_drvdata(dev);
    iounmap(ledinfo->base);
    cdev_del(&(ledinfo->cdev));
    kfree(ledinfo);
    unregister_chrdev_region(MKDEV(LED_MAJOR,dev->id),1);

    return 0;
}

static const struct of_device_id led_of_match[] = {
	{ .compatible = "ex_led" },
	{ /* Sentinel */ }
};

struct platform_driver ex_drv={
    .driver={
        .name="led_drv",
        .owner=THIS_MODULE,
        .of_match_table=led_of_match,
    },
    .probe=drv_probe,
    .remove=drv_remove,
};

static int __init drv_init(void){
    printk("init\n");
    rccbase =ioremap(RCC_MP_AHB4ENSETR,4);
    if(rccbase==NULL){
        printk("error!!\n");
        return -ENOMEM;
    }
    *rccbase=0xFFF;
    printk("%p",rccbase);
    platform_driver_register(&ex_drv);
    printk("exdrv register ok\n");
    return 0;
}

static void __exit drv_exit(void){
    platform_driver_unregister(&ex_drv);
}

module_init(drv_init);
module_exit(drv_exit);
MODULE_LICENSE("GPL");