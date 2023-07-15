#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>

int vbus_match(struct device *dev,struct device_driver *drv){
    dump_stack();
    return 1;
}

struct bus_type vbus={
    .name="vbus",
    .match=vbus_match
};

EXPORT_SYMBOL(vbus);

static int __init vbus_init(void){
    return bus_register(&vbus);
}
static void __exit vbus_exit(void){
    bus_unregister(&vbus);
}

module_init(vbus_init);
module_exit(vbus_exit);
MODULE_LICENSE("Dual BSD/GPL");