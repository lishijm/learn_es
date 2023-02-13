#include<stdio.h>
int main(){
    int arr[4]={1,2,3,4};
    int *p;
    int i;
    p=arr;
    for(i=0;i<100;i++){
        printf("%d,",*p);
        p++;
    }
}