#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/timer.h>
#include <linux/workqueue.h>

struct fskey_info
{
	int irq;
	struct timer_list timer;
	struct tasklet_struct task;
	struct work_struct work;
	struct delayed_work dwork;
};

irqreturn_t fskey_handler(int irq, void * arg)
{
	struct fskey_info* info = arg;
	printk("key pressed\n");
	mod_timer(&info->timer, jiffies + HZ);
	tasklet_schedule(&info->task);
	schedule_work(&info->work);
	schedule_delayed_work(&info->dwork, 2*HZ);
	return IRQ_WAKE_THREAD;
}

irqreturn_t fskey_thread(int irq, void* arg)
{
	printk("thread run\n");
	return IRQ_HANDLED;
}

void fskey_timeout(struct timer_list * timer)
{
	printk("timeout\n");
}

void fskey_tasklet(unsigned long data)
{
	struct fskey_info* info = (void*)data;
	printk("irq %d: run tasklet\n", info->irq);
}

void fskey_work(struct work_struct *work)
{
	printk("run work: %lu\n", jiffies);
}

int fskey_probe(struct platform_device* dev)
{
	struct fskey_info* info = devm_kmalloc(&(dev->dev), sizeof(struct fskey_info), GFP_KERNEL);
	int ret;

	if (!info)
	{
		return -ENOMEM;
	}

	info->irq = platform_get_irq(dev, 0);
	if (info->irq < 0)
	{
		return info->irq;
	}

	printk("irq: %d\n", info->irq);

	timer_setup(&info->timer, fskey_timeout, 0);

	tasklet_init(&info->task, fskey_tasklet, (unsigned long)info);

	INIT_WORK(&(info->work), fskey_work);

	INIT_DELAYED_WORK(&(info->dwork), fskey_work);

	ret = devm_request_threaded_irq(&(dev->dev), info->irq, fskey_handler, fskey_thread, 0, "fskey", info);
	if (ret < 0)
	{
		return ret;
	}

	return 0;
}

int fskey_remove(struct platform_device* dev)
{
	return 0;
}

static struct of_device_id fskey_matches[] = {
	{.compatible = "ex_key"},
	{}
};

struct platform_driver fskey = {
	.driver = {
		.name = "fskey",
		.owner = THIS_MODULE,
		.of_match_table = fskey_matches,
	},
	.probe = fskey_probe,
	.remove = fskey_remove,
};

module_platform_driver(fskey);

MODULE_LICENSE("GPL");

