#include<stdio.h>
int main(){
    int num1,num2,row;
    scanf("%d",&row);
    int cor=row;
    for(num1=1;num1<=row;num1++){
        for(num2=1;num2<=row-cor+1;num2++){
            printf("\t");
        }
        for(num2=num1;num2<=row;num2++){
            printf("%d*%d=%d\t",num1,num2,num1*num2);
        }
        printf("\n");
        cor--;
    }
}