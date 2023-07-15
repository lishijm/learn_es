#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

int add(int sum1,int sum2);

static int __init demo_init(void){
    int a=3,b=4;
    int sum=add(a,b);
    printk("sum = %d\n",sum);
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