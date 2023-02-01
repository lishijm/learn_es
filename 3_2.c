#include<stdio.h>
//#define PI 3.14
//#define ADD(a,b) a+b 宏变量只是替换，不能运算
int ADD(int a,int b){
    int c=a+b;
    return c;
}
int main(){
    
    /*int add1,add2;
    int sum;
    scanf("%d%d",&add1,&add2);
    sum=ADD(add1,add2);*/
    printf("%d\n",ADD(3,4)*ADD(2,3));

    /*double r;
    while(1){
        scanf("%lf",&r);
        printf("circle round=%lf\n",PI*r*2);
        printf("circle square=%lf\n",PI*r*r);
    }*/

    return 0;
}