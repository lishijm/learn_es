#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/timer.h>
#include <linux/interrupt.h>

struct exkey_info {
    int irq;
    struct timer_list timer;
    struct tasklet_struct task;
};

irqreturn_t exkey_handler(int irq,void * arg){
    struct exkey_info * info=arg;
    printk("exkey pressed\n");
    mod_timer(&info->timer,jiffies+HZ);
    tasklet_schedule(&info->task);
    return IRQ_WAKE_THREAD;
}

irqreturn_t exkey_thread(int irq,void *arg){
    printk("thread run\n");
    return IRQ_HANDLED;
}

void exkey_timeout(struct timer_list * timer){
    printk("timeout\n");
}

void exkey_tasklet(unsigned long data){
    struct exkey_info *info=(void *)data;
    printk("irq %d tasklet run\n",info->irq);
}

int exkey_probe(struct platform_device *dev){
    struct exkey_info *info=devm_kmalloc(&(dev->dev), sizeof(struct exkey_info), GFP_KERNEL);
    int ret;
    if(!info){
        return -ENOMEM;
    }
    info->irq=platform_get_irq(dev,0);
    if(info->irq<0){
        return info->irq;
    }
    printk("irq:%d\n",info->irq);

    timer_setup(&info->timer,exkey_timeout,0);

    tasklet_init(&info->task,exkey_tasklet,(unsigned long)info);
    
    ret=devm_request_threaded_irq(&(dev->dev), info->irq, exkey_handler, exkey_thread, 0, "ex_key", info);
    if(0>ret){
        return -EINVAL;
    }

    return 0;
}
int exkey_remove(struct platform_device * dev){
    return 0;
}

struct of_device_id exkey_matches[]={
    {.compatible="ex_key"},
    {}
};

static struct platform_driver exkey={
    .driver={
        .name="ex_key_drv",
        .owner=THIS_MODULE,
        .of_match_table = exkey_matches,
    },
    .probe=exkey_probe,
    .remove=exkey_remove,
};

module_platform_driver(exkey);
MODULE_LICENSE("GPL");