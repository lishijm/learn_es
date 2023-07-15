#include <linux/module.h>
#include <linux/init.h>

static int __init demo_init(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    return 0;
}
static void __exit  demo_exit(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    return ;
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("GPL");