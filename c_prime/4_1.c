#include<stdio.h>
int main(){
    int a=4;
    if(5<a<-1){//此种先与前面数的比较，比较完真为1；假为0；之后0/1再与后面的数比较
        printf("true\n");
    }
    else printf("false\n");
    if(5<a&&a<3){
        printf("true02\n");
    }
    else printf("false02\n");
    if(a=5){
        printf("true03\n");
    }
    else printf("false03\n");
    if(a==6){
        printf("true04\n");
    }
    else printf("false04\n");
    /*
    int b=4;
    int c;
    c=a<3&&b++;//截断法则，遇假则不再运算
    printf("%d %d\n",b,c);
    */
    int b=4;
    int c;
    c=a<3||b++;//截断法则，遇真则不再运算

    printf("%d %d\n",b,c);
    printf("%d\n",c++);//先赋值再运算
    printf("%d\n",++c);//先运算再赋值
    
    return 0;
}