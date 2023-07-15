#include<stdio.h>
int add(int a,int b){
    int c;
    c=a+b;
    printf("%d",c);
}
int sub(int a,int b){
    int c;
    c=a-b;
    printf("%d",c);
}
int mul(int a,int b){
    int c;
    c=a*b;
    printf("%d",c);
}
float div(float a,float b){
    float c;
    c=a/b;
    printf("%f",c);
}
#include<stdio.h>
int main(){
    int a,b;
    char ch;
    scanf("%d%c%d",&a,&ch,&b);
    switch(ch){
        case '+':add(a,b);
        break;
        case '-':sub(a,b);
        break;
        case '*':mul(a,b);
        break;
        case '/':div(a,b);
        break;
    }

    return 0;
}