#include <linux/module.h>
#include <linux/platform_device.h>

typedef struct {// GPIO  的结构体
	volatile unsigned int  MODER;
	volatile unsigned int OTYPER;
	volatile unsigned int OSPEEDER;
	volatile unsigned int  PUPDR;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
}GPIO_DEF;

struct resource fsled1_res[] = {
	[0] = {
		.start = 0x50006000,
		.end = 0x50006000 + sizeof(GPIO_DEF) - 1,
		.name = NULL,
		.flags = IORESOURCE_MEM,
		.desc = IORES_DESC_NONE
	},
};

struct resource fsled2_res[] = {
	[0] = DEFINE_RES_MEM(0x50007000, sizeof(GPIO_DEF)),
};

struct resource fsled3_res[] = {
	[0] = DEFINE_RES_MEM(0x50006000, sizeof(GPIO_DEF)),
};

void fsled_release(struct device *dev)
{
}

struct platform_device fsled1 = {
	.name = "ex_led",
	.id = 1,
	.num_resources = ARRAY_SIZE(fsled1_res),
	.resource = fsled1_res,
	.dev = {
		.release = fsled_release,
		.platform_data = (void*)10,
	},
};

struct platform_device fsled2 = {
	.name = "ex_led",
	.id = 2,
	.num_resources = ARRAY_SIZE(fsled2_res),
	.resource = fsled2_res,
	.dev = {
		.release = fsled_release,
		.platform_data = (void*)10,
	},
};

struct platform_device fsled3 = {
	.name = "ex_led",
	.id = 3,
	.num_resources = ARRAY_SIZE(fsled3_res),
	.resource = fsled3_res,
	.dev = {
		.release = fsled_release,
		.platform_data = (void*)8,
	},
};

static int __init fsdev_init(void)
{
	platform_device_register(&fsled1);
	platform_device_register(&fsled2);
	platform_device_register(&fsled3);
	return 0;
}

static void __exit fsdev_exit(void)
{
	platform_device_unregister(&fsled1);
	platform_device_unregister(&fsled2);
	platform_device_unregister(&fsled3);
}

module_init(fsdev_init);
module_exit(fsdev_exit);

MODULE_LICENSE("GPL");

