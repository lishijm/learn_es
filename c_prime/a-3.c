#include<stdio.h>
int main(){
    int a=10;
    int b=20;
    int const*p;     //锁定赋值功能。只能改变指向
    int *const cp=&a;//锁定指针指向。只能改变赋值
    int const*const ccp=&a;//all read only
    p=&a;
    p=&b;
    //*p=30;err
    printf("%d",*p);

    *cp=30;
    //cp=&b;err
    printf("%d",a);

    //*ccp=40;err
    //*ccp=&b;err

    return 0;

}