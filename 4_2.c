#include<stdio.h>
int main(){
    //int a=0,b=0,c=0,d=0;
    /*c=(a-=a-5);
    (a=b,b+=4);
    printf("%d %d %d\n",a,b,c);*/

    int a=3,b=4,c=5,d=0;
    d=a>b?b++:c++;//三目运算符，若关系式1成立则该值为关系式2，若关系式1不成立则值为关系式3
    printf("%d %d %d %d",a,b,c,d);

    return 0;
}