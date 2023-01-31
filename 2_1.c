//十进制转换各进制
#include<stdio.h>
int main(){
    int num,tmp;
    int b[32];
    int counter=0;
    scanf("%d",&num);
    printf("%d,%#x,%#o,",num,num,num);
    tmp=num;

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