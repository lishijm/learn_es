#include<stdio.h>

int main(){
    int arr[4]={56,48,72,39},i,j,swap;
    for(i=0;i<4-1;i++){
        for(j=0;j<4-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    for(i=0;i<4;i++){
        printf("%d,",arr[i]);
    }

    return 0;
}