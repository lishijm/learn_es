//循环二分
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binlookup(int arr[],int item,int n){
    int low=0,high=n-1,mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(item==arr[mid]){
            return mid;
        }
        else if(item<arr[mid]){
            high=mid-1;
        }
        else if(item>arr[mid]){
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[13]={12,13,15,23,25,26,38,42,48,54,75,78,84};
    int findnum;
    scanf("%d",&findnum);
    int cop=binlookup(arr,findnum,13);
    if(cop==-1){
        printf("not found");
    }
    else{
        printf("%d",cop);
    }
    return 0;
}