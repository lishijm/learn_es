#include<stdio.h>
int add(int a,int b){
    int c;
    c=a+b;
    return c;
}
int sub(int a,int b){
    int c;
    c=a-b;
    return c;
}
int mul(int a,int b){
    int c;
    c=a*b;
    return c;
}float div(float a,float b){
    float c;
    c=a/b;
    return c;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);

    printf("add=%d\nmul=%d\ndiv=%d\ndiv=%f\n",add(a,b),sub(a,b),mul(a,b),div(a,b));

    return 0;
}