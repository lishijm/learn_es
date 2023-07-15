#include<stdio.h>
int main(){
    int num,i=0;
    scanf("%d",&num);
    while(num){
        if(num%2==1){
            i++;
        }
        num=num/2;
    }
    printf("%d",i);
}