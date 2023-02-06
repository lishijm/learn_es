#include<stdio.h>
int main(){

    int counter,sum=0;
    for(counter=1;counter<=100;counter++){
        sum+=counter;
        printf("%d\n",sum);
    }

    printf("%d",sum);

    return 0;
}