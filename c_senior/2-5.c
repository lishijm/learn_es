#include<stdio.h>
int fx(int a){
    printf("fx=%p\n",&a);
    return a;
}

int main(){
    int a=20;
    int (*p)(int)=&fx;
    int (*q)(int)=fx;
    int (**pp)(int)=&p;
    printf("main=%p\n",pp);
    //printf("fxmain%p\n")
    //printf("%p",q(a));
    return 0;
}