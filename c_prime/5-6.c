#include<stdio.h>
int main(){
    int row,counter1,counter2,counter3,counter4;
    scanf("%d",&row);
    counter4=row;
    for(counter1=1;counter1<=row;counter1++){
        for(counter2=counter4;counter2>1;counter2--){
            printf(" ");
        }
        for(counter3=0;counter3<(counter1*2)-1;counter3++){
            printf("*");
        }
        printf("\n");
        counter4--;
    }

    return 0;
}