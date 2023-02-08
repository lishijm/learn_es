#include<stdio.h>
int main(){
    int a=10;
    int *p,**pp;
    p=&a;
    pp=&p;
    printf("%d",**pp);
}