#include<stdio.h>
int main(){
    int *p,i,**pp;
    int num[]={1,2,3,4};
    p=num;
    pp=&p;

    for(i=0;i<4;i++,p++){
        printf("%d\n",*p);
        printf("%p\n",&num[i]);
        printf("%p\n",&p);
        printf("%d\n",**pp);
        printf("\n");
    }

    return 0;
}