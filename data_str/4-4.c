//递归二分
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binlookup(int arr[],int item,int low,int high){
    if(low<=high){
        int mid=(high+low)/2;
        //printf("%d ",arr[mid]);
        //printf("x%d ",item);
        if(item==arr[mid]){
            return mid;
        }
        else if(item<arr[mid]){
            high=mid-1;
            binlookup(arr,item,low,high);
        }
        else if(item>arr[mid]){
            low=mid+1;
            binlookup(arr,item,low,high);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int arr[13]={12,13,15,23,25,26,38,42,48,54,75,78,84};
    int findnum;
    scanf("%d",&findnum);
    int high=12,low=0;
    int cop=binlookup(arr,findnum,low,high);
    //printf("%d",cop);
    if(cop==-1){
        printf("not found");
    }
    else{
        printf("%d",cop);
    }
    return 0;
}