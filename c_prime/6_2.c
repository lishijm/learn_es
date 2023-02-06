#include<stdio.h>

int main(){
    int arr[5]={66,33,52,24,88},i,j,swap;
    for(i=1;i<5;i++){
        for(j=0;j<5-i;j++){
            if(arr[j]>arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    for(i=0;i<5;i++){
        printf("%d,",arr[i]);
    }

    return 0;
}