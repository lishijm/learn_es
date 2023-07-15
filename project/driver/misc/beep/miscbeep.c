#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <asm/mach/map.h>
#include <asm/io.h>


#define MISCBEEP_NAME "miscbeep"
#define MISCBEEP_MINOR 144
#define BEEPOFF 0
#define BEEPON 1

struct miscbeep_dev{
    dev_t devid;
    struct cdev cdev;
    struct class *class;
    struct device *device;
    int beep_gpio;
};

struct miscbeep_dev miscbeep;

static int beep_gpio_init(struct device_node *nd){
    int ret;
    
    miscbeep.beep_gpio=of_get_named_gpio(nd,"beep-gpio",0);
    if(!gpio_is_valid(miscbeep.beep_gpio)){
        printk("miscbeep :Failed to get beep-gpio\r\n");
        return -EINVAL;
    }
    printk("gpio=%d",miscbeep.beep_gpio);

    ret=gpio_request(miscbeep.beep_gpio,"beep");
    if(ret){
        printk("beep:failed to request beep-gpio\r\n");
        return ret;
    }

    gpio_direction_output(miscbeep.beep_gpio,1);
    return 0;
}

static int miscbeep_open(struct inode*inode,struct file *filp){
    return 0; 
}

static ssize_t miscbeep_write(struct file *filp,const char __user *buf,size_t cnt,loff_t *offt){
    int ret;
    unsigned char databuf[1];
    unsigned char beepstat;
    ret=copy_from_user(databuf,buf,cnt);
    if(ret<0){
        printk("kernel write failed!\r\n");
        return -ESERVERFAULT;
    }
    beepstat=databuf[0];
    if(beepstat==BEEPON){
        gpio_set_value(miscbeep.beep_gpio,0);
    }
    else if(beepstat==BEEPOFF){
        gpio_set_value(miscbeep.beep_gpio,1);
    }
    return 0;
}

static struct file_operations miscbeep_fops={
    .owner=THIS_MODULE,
    .open=miscbeep_open,
    .write=miscbeep_write,
};

static struct miscdevice beep_miscdev={
    .minor=MISCBEEP_MINOR,
    .name=MISCBEEP_NAME,
    .fops=&miscbeep_fops,
};

static int miscbeep_probe(struct platform_device *pdev){
    int ret=0;
    printk("beep driver end device was matched!\r\n");

    ret=beep_gpio_init(pdev->dev.of_node);
    if(ret<0){
        return ret;
    }
    
    ret=misc_register(&beep_miscdev);
    if(ret<0){
        printk("misc device register failed\r\n");
        goto free_gpio;
    }
    
    return 0;
    
free_gpio:
    gpio_free(miscbeep.beep_gpio);
    return -EINVAL;
}

static int miscbeep_remove(struct platform_device *dev){
    gpio_set_value(miscbeep.beep_gpio,1);
    gpio_free(miscbeep.beep_gpio);
    misc_deregister(&beep_miscdev);
    return 0;
}

static const struct of_device_id beep_of_match[]={
    {.compatible="atk,beep"},
    {/*sentinel*/}
};

static struct platform_driver beep_driver={
    .driver={
        .name="stm32mp1-beep",
        .of_match_table=beep_of_match,
    },
    .probe=miscbeep_probe,
    .remove=miscbeep_remove,
};

static int __init miscbeep_init(void){
    return platform_driver_register(&beep_driver);
}

static void __exit miscbeep_exit(void){
    platform_driver_unregister(&beep_driver);
}

module_init(miscbeep_init);
module_exit(miscbeep_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("lishijm@outlook.com");
MODULE_INFO(intree,"Y");