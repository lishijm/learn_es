#include<stdio.h>
int main(){
    int year,month,day,dn=0,i;
    scanf("%d%d%d",&year,&month,&day);
    int monthnum[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||year%400==0){
        monthnum[1]=29;
    }
    
    if(month>12||day>monthnum[month-1]){
        printf("err");
    }
    else{
        for(i=1;i<month;i++){
            dn+=monthnum[i-1];
        }
        dn+=day;
        printf("%d",dn);
    }

    return 0;
}