//十进制转换各进制
#include<stdio.h>
int main(){
    int a,tmp;
    int b[32];
    int counter=0;

    scanf("%d",&a);
    printf("%d,%#x,%#o,",a,a,a);
    tmp=a;

    while(tmp>0){
        b[counter]=(tmp%2);
        counter++;
        tmp=tmp/2;
    }
    counter--;
    for(counter;counter>=0;counter--){
        printf("%d",b[counter]);
    }
    printf("\n");

    return 0;
}