#include<stdio.h>
int main()
{
    int year,month;
    scanf("%d%d",&year,&month);
    //printf("%d%d",year,month);
    if(((year%4==0&&year%100!=0)||year%400==0)&&2==month){
        printf("29\n");
    }
    else{
        switch(month){
            case 2:printf("28\n");
            break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:printf("31\n");
            break;
            default:printf("30\n");
        }
    }

    return 0;
}