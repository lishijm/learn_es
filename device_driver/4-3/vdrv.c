#include <linux/module.h>
#include <linux/device.h>

extern struct bus_type vbus;

int vdrv_probe(struct device *dev){
    dump_stack();
    return 0;
}

int vdrv_remove(struct device *dev){
    dump_stack();
    return 0;
}

struct device_driver vdrv={
    .name="vdrv",
    .bus=&vbus,
    .probe=vdrv_probe,
    .remove=vdrv_remove
};

static int __init vdrv_init(void){
    return driver_register(&vdrv);
}

static void __exit vdrv_exit(void){
    driver_unregister(&vdrv);
}

module_init(vdrv_init);
module_exit(vdrv_exit);

MODULE_LICENSE("Dual BSD/GPL");