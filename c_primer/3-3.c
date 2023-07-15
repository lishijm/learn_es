#include<stdio.h>
//int a;        //若用static修饰全局变量则限制作用域只能在本文件中使用
int main(){
    int counter;
    for(counter=0;counter<5;counter++){
        static int a=0;
        //static修饰局部变量：延长局部变量生命周期（使之从函数结束括号释放延长为整个程序寿命）；
        //如果局部变量没有初始化，其值为0；
        //若初始化，则只能初始化一次
        a++;
        printf("%d\n",a);
    }
    //int b;
    //printf("%d\n%d\n",a,b);
    return 0;
}