#include<stdio.h>
int main(){
    int *p[5];
    int brr[5][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    int i,j;
    for(i=0;i<5;i++){
        p[i]=brr[i];
    }
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("%d",*(p[i]+j));
        }
    }

    return 0;
}