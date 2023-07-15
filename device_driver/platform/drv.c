#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/uaccess.h>

#define FSLED_MAJOR 239

typedef struct {// GPIO  的结构体
	volatile unsigned int MODER;
	volatile unsigned int OTYPER;
	volatile unsigned int OSPEEDER;
	volatile unsigned int PUPDR;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
}GPIO_DEF;

struct fsled_info
{
	GPIO_DEF* base;
	int pin;
	struct cdev cdev;
};

int fsled_open(struct inode * inodp, struct file * filp)
{
	struct fsled_info* ledinfo = container_of(inodp->i_cdev, struct fsled_info, cdev);
	filp->private_data = ledinfo;
	printk(KERN_INFO "fsled_open\n");
	printk(KERN_INFO "base: %p, pin: %d\n", ledinfo->base, ledinfo->pin);
	return 0;
}

int fsled_release(struct inode * inodp, struct file * filp)
{
	return 0;
}

ssize_t fsled_write(struct file * filp, const char __user * buf, size_t size, loff_t * pos)
{
	struct fsled_info* ledinfo = (struct fsled_info*)filp->private_data;
	char cmd;

	printk(KERN_INFO "fsled_write\n");
	get_user(cmd, buf);
	printk(KERN_INFO "cmd: %c\n", cmd);

	if (cmd == '1')
	{
		//turn on
		ledinfo->base->ODR |= (1 << ledinfo->pin);
		printk(KERN_INFO "turn led on\n");
	}

	if (cmd == '0')
	{
		//turn off
		ledinfo->base->ODR &= ~(1 << ledinfo->pin);
		printk(KERN_INFO "turn led off\n");
	}

	return size;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = fsled_open,
	.release = fsled_release,
	.write = fsled_write
};

int fsdrv_probe(struct platform_device * dev)
{
	struct fsled_info* ledinfo;
	struct resource* res;
	dev_t devno = MKDEV(FSLED_MAJOR, dev->id);
	int ret = register_chrdev_region(devno, 1, "fsled");
	if (ret)
	{
		printk(KERN_ERR "register_chrdev_region failed\n");
		return ret;
	}

	ledinfo = kmalloc(sizeof(struct fsled_info), GFP_KERNEL);
	if (!ledinfo)
	{
		unregister_chrdev_region(devno, 1);
		return -ENOMEM;
	}

	cdev_init(&(ledinfo->cdev), &fops);
	ledinfo->cdev.owner = THIS_MODULE;
	ret = cdev_add(&(ledinfo->cdev), devno, 1);
	if (ret)
	{
		unregister_chrdev_region(devno, 1);
		kfree(ledinfo);
		return ret;
	}

	res = platform_get_resource(dev, IORESOURCE_MEM, 0);
	if (res == NULL)
	{
		unregister_chrdev_region(devno, 1);
                kfree(ledinfo);
		cdev_del(&(ledinfo->cdev));
		return -ENOENT;
	}

	ledinfo->base = ioremap(res->start, resource_size(res));
	if (ledinfo->base == NULL)
	{
		unregister_chrdev_region(devno, 1);
                kfree(ledinfo);
                cdev_del(&(ledinfo->cdev));
		return -ENOMEM;
	}

	ledinfo->pin = (int)dev->dev.platform_data;

	ledinfo->base->MODER = ledinfo->base->MODER & ~(3 << (ledinfo->pin << 1));
	ledinfo->base->MODER = ledinfo->base->MODER | (1 << (ledinfo->pin <<1));

	platform_set_drvdata(dev, ledinfo);

	printk(KERN_INFO "led%d initialized\n", dev->id);

	return 0;
}

int fsdrv_remove(struct platform_device * dev)
{
	struct fsled_info* ledinfo = platform_get_drvdata(dev);
	iounmap(ledinfo->base);
	cdev_del(&(ledinfo->cdev));
	kfree(ledinfo);
	unregister_chrdev_region(MKDEV(FSLED_MAJOR, dev->id), 1);

	return 0;
}

struct platform_driver fsdrv = {
	.driver = {
		.name = "fsled",
		.owner = THIS_MODULE,
	},
	.probe = fsdrv_probe,
	.remove = fsdrv_remove,
};

static int __init fsdrv_init(void)
{
#define RCC_MP_AHB4ENSETR 0x50000a28
	unsigned int* base = ioremap(RCC_MP_AHB4ENSETR, 4);
	if (base == NULL)
	{
		return -ENOMEM;
	}
	*base = 0xFFF;
	platform_driver_register(&fsdrv);
	return 0;
}

static void __exit fsdrv_exit(void)
{
	platform_driver_unregister(&fsdrv);
}

module_init(fsdrv_init);
module_exit(fsdrv_exit);

MODULE_LICENSE("GPL");

