#include <linux/module.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "ioctl.h"
#include "./stm32mp1xx_gpio.h"
#include "./stm32mp1xx_rcc.h"

#define CDEV_NAME "democdev"
#define COUNT 3

#define LED1_ON (vgpioe->ODR = vgpioe->ODR | ( 1 << 10))
#define LED1_OFF (vgpioe->ODR = vgpioe->ODR & ~( 1 << 10))

#define LED2_ON (vgpiof->ODR = vgpiof->ODR | ( 1 << 10))
#define LED2_OFF (vgpiof->ODR = vgpiof->ODR & ~( 1 << 10))

#define LED3_ON (vgpioe->ODR = vgpioe->ODR | ( 1 << 8))
#define LED3_OFF (vgpioe->ODR = vgpioe->ODR & ~( 1 << 8))

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

	vgpioe->MODER = vgpioe->MODER & ~(3  << 20);
	vgpioe->MODER = vgpioe->MODER | ( 1 << 20);
	vgpioe->OTYPER = vgpioe->OTYPER & ~(1  << 10);
	vgpioe->OSPEEDR &=(~(0x3<<20));
	vgpioe->PUPDR &=(~(0x3<<20));

    vgpiof->MODER = vgpiof->MODER & ~( 3 << 20);
    vgpiof->MODER = vgpiof->MODER | ( 1 << 20);
	vgpiof->OTYPER = vgpiof->OTYPER & ~(1  << 10);
	vgpiof->OSPEEDR &=(~(0x3<<20));
	vgpiof->PUPDR &=(~(0x3<<20));

    vgpioe->MODER = vgpioe->MODER & ~(3  << 16);
	vgpioe->MODER = vgpioe->MODER | ( 1 << 16);
	vgpioe->OTYPER = vgpioe->OTYPER & ~(1  << 8);
	vgpioe->OSPEEDR &=(~(0x3<<16));
	vgpioe->PUPDR &=(~(0x3<<16));

}

int demo_open(struct inode *inode, struct file *file)
{
	printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    current_devno = inode->i_rdev;
    minor_device_number=MINOR(current_devno);
	return 0;
}

long demo_ioctl (struct file *file, unsigned int cmd, unsigned long args)
{
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    switch (minor_device_number)
    {
    case 0:
        switch (cmd)
        {
        case IOCTL_CMD_LED_ON:
            LED1_ON;
            break;
        case IOCTL_CMD_LED_OFF:
            LED1_OFF;
            break;
        default:
            break;
        }
        break;
    case 1:
        switch (cmd)
        {
        case IOCTL_CMD_LED_ON:
            LED2_ON;
            break;
        case IOCTL_CMD_LED_OFF:
            LED2_OFF;
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (cmd)
        {
        case IOCTL_CMD_LED_ON:
            LED3_ON;
            break;
        case IOCTL_CMD_LED_OFF:
            LED3_OFF;
            break;
        default:
            break;
        }
        break;
    default:
        break;
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
    .unlocked_ioctl=demo_ioctl,
    .release=demo_close,
};

static int __init demo_init(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    vrcc=ioremap((phys_addr_t)RCC,4);
    if(NULL==vrcc){
        printk("rcc ioremap error\n");
        cdev_del(&democdev);
        unregister_chrdev_region(devno,COUNT);
        return -1;
    }
    vgpioe=ioremap((phys_addr_t)GPIOE,4);
    if(NULL==vgpioe){
        printk("gpioe ioremap error\n");
        cdev_del(&democdev);
        unregister_chrdev_region(devno,COUNT);
        return -1;
    }
    vgpiof=ioremap((phys_addr_t)GPIOF,4);
    if(NULL==vgpiof){
        printk("gpiof ioremap error\n");
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