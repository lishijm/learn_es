#include<stdio.h>
int main(){
    int a,b,c;
    char ch;
    scanf("%d%c%d",&a,&ch,&b);
    switch(ch){
        case '+':c=a+b;
        printf("%d",c);
        break;
        case '-':c=a-b;
        printf("%d",c);
        break;
        case '*':c=a*b;
        printf("%d",c);
        break;
        case '/':float af,bf,cf;
        af=a;bf=b;
        cf=af/bf;
        printf("%f",cf);
        break;
    }

    return 0;
}