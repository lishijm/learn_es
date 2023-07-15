#include<stdio.h>
int main(){
    int max=-2147483648,cmax=-2147483648;
    int i,x;

    scanf("%d",&x);
    int arr[x];
    for(i=0;i<x;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<x;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    printf("%d\n",max);

    for(i=0;i<x;i++){
        if(cmax<arr[i]&&arr[i]<max){
            cmax=arr[i];
        }
    }
    printf("%d\n",cmax);

    return 0;
}