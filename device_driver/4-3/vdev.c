#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>

extern struct bus_type vbus;

void vdev_release(struct device *dev){
    dump_stack();
}

struct device vdev={
    .init_name="vdev",
    .bus=&vbus,
    .release=vdev_release
};

static int __init vdev_init(void){
    return device_register(&vdev);
}
static void __exit vdev_exit(void){
    device_unregister(&vdev);
}

module_init(vdev_init);
module_exit(vdev_exit);
MODULE_LICENSE("Dual BSD/GPL");