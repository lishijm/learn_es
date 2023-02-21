#include"../include/class.h"

void avr(stu (*p)[3],int s){
    int i;
    float sum=0;

    for(i=0;i<3;i++){
        sum+=((*p)+i)->mark[s];
    }
    printf("%d avr mark=%.2f\n",s,sum/3);
}