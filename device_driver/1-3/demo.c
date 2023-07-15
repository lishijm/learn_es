#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

int back_light=10;
module_param(back_light,int,0664);
MODULE_PARM_DESC(back_light,"this is lcd back light");

int tmp=1;
module_param(tmp,int,0664);
MODULE_PARM_DESC(ttmp,"this is a test");

char *str ="demo 1-3";
module_param(str,charp,0664);
MODULE_PARM_DESC(p,"this is start words");

int arr[10]={1,2,3,4,5,6,7,8,9,0};
int len;
module_param_array(arr,int,&len,0664);
MODULE_PARM_DESC(arr,"this is a array");

static int __init demo_init(void){
    int i;
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    printk("back_light = %d\n",back_light);
    printk("tmp = %d\n",tmp);
    printk("str:%s",str);
    for(i=0;i<len;i++){
        printk("%d",arr[i]);
    }
    printk("\n");
    return 0;
}
static void __exit  demo_exit(void){
    printk(KERN_ERR "%s,%s,%d\n",__func__,__FILE__,__LINE__);
    return ;
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("GPL");