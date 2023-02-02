#include<stdio.h>
int main(){
    //int a=0,b=0,c=0,d=0;
    /*c=(a-=a-5);
    (a=b,b+=4);
    printf("%d %d %d\n",a,b,c);*/

    /*int a=3,b=4,c=5,d=0;
    d=a>b?b++:c++;
    printf("%d %d %d %d",a,b,c,d);*/

    int a=3,b=4,c=0,d=0;
    d=(a++,++b,c++);
    printf("%d %d %d %d\n",a,b,c,d);
    d=(a++,b+1,a+b);
    printf("%d %d %d %d\n",a,b,c,d);


    return 0;
}