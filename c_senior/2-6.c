#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int main(){
    int (*p[2])(int,int)={add,sub};
    //int (*p)[2](int,int)={add,sub};
    printf("%d",(p[0])(4,3));
    printf("%d",(p[1])(4,3));
    printf("%d",p[0](4,3));
    printf("%d\n",p[1](4,3));
    int (**pp)(int,int)=&p[0];
    printf("%p",pp);
    return 0;
}