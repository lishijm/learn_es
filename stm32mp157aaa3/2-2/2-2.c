#include <stdio.h>

int main(){
    long long unsigned int a=0x12345678;
    long long unsigned int b;
    scanf("%d",&b);
    long long unsigned int op=0xffffffff;
    a=(a&(op>>25))|(a&(op<<18));
    a=a|(b<<7);
    printf("%0x",a);
}