#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>

struct exkey_info {
    int irq;
};

irqreturn_t exkey_handler(int irq,void * arg){
    printk("exkey pressed\n");
    return IRQ_WAKE_THREAD;
}

irqreturn_t exkey_thread(int irq,void *arg){
    printk("thread\n");
    return IRQ_HANDLED;
}

int exkey_probe(struct platform_device *dev){
    struct exkey_info *info=kmalloc(sizeof(struct exkey_info),GFP_KERNEL);
    if(!info){
        return -ENOMEM;
    }
    info->irq=platform_get_irq(dev,0);
    if(info->irq<0){
        kfree(info);
        return info->irq;
    }
    printk("irq:%d\n",info->irq);

    if(request_threaded_irq(info->irq,exkey_handler,exkey_thread,0,"ex_key",NULL)){
        kfree(info);
        return -EINVAL;
    }
    platform_set_drvdata(dev,(void *)info->irq);

    return 0;
}
int exkey_remove(struct platform_device * dev){
    struct exkey_info * info=platform_get_drvdata(dev);
    free_irq(info->irq,NULL);
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