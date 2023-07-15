#include <stdio.h>

int main(){
#if 0
    unsigned int *p;
    p=(unsigned int *)0x50002014;
    printf("%0x",*p);
    *p=*p^(1<<7);
    printf("%0x",*p);
    *p=*p^(1<<7);
    printf("%0x",*p);
#endif
#if 0
    long long unsigned int a=0x1FFFFFFFF;
    long long unsigned int b=0x200000001;
    printf("%0x",b-a);
#endif
#if 0
    if((a&(1<<12))==0){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
#endif
    return 0;
}