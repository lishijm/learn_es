#include<stdio.h>
int main(){
    int a=1;
    printf("%d\n",a++);//先赋值再运算
    printf("%d\n",++a);//先运算再赋值

    return 0;
}