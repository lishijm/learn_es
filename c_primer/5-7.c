#include<stdio.h>
int main(){
    int row,counter1,counter2,counter3,counter4,counter5;
    scanf("%d",&row);
    counter4=row/2;
    counter5=2;
    for(counter1=1;counter1<=row;counter1++){
        if(counter1<=(row+1)/2){
            for(counter2=counter4+1;counter2>1;counter2--){
                printf(" ");
            }
            for(counter3=0;counter3<(counter1*2)-1;counter3++){
                printf("*");
            }
            printf("\n");
            counter4--;
        }
        else{
            //printf("%d%d",row,(row - counter1) * 2 - 1);
            for(counter2=1;counter2<counter5;counter2++){
                printf(" ");
            }
            for(counter3=0;counter3<(row-counter1)*2+1;counter3++){
                printf("*");
            }
            printf("\n");
            counter5++;
        }
    }

    return 0;
}