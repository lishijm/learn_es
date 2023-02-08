#include<stdio.h>
int add(int a,int b){
    int c;
    c=a+b;
    return c;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);

    printf("%d",add(a,b));

    return 0;
}