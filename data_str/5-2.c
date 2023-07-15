#include<stdio.h>

int quickpass(int arr[],int low,int high){
    int key=0;
    if(NULL==arr){
        return -1;
    }
    key=arr[low];
    while(low<high){
        while(low<high&&key<arr[high]){
            high--;
        }
        arr[low]=arr[high];
        while (low<high && key>=arr[low]){
            low++;
        }
        arr[high]=arr[low];
    }
    arr[low]=key;
    return low;
}

void quicksort(int arr[],int low,int high){
    if(low>high){
        return ;
    }
    int mid=quickpass(arr,low,high);
    quicksort(arr,low,mid-1);
    quicksort(arr,mid+1,high);
}

int main(){
    int arr[5]={5,3,8,1,7};
    int high=5-1;
    int low=0;
    quicksort(arr,low,high);
    int i;
    for(i=0;i<5;i++){
        printf("%d",arr[i]);
    }
}