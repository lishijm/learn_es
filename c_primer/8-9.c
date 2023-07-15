#include<stdio.h>
int in(int *rp,int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",rp);
        rp++;
    }
}
int *sor(int *rp,int n){
    int arr[n];
    int i,j,temp;
    int *re;
    for(i=0;i<n;i++){
        arr[i]=*rp;
        rp++;
        //printf("%d",arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    re=arr;
    return re;
}
int out(int *rp,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d",*rp);
        rp++;
    }
}
int max(int *rp,int n){
    printf("\nmax=%d\n",*(rp+n-1));
}
int main(){
    int i,n,*sop;
    scanf("%d",&n);
    int arr[n];

    in(arr,n);
    sor(arr,n);
    sop=sor(arr,n);
    for(i=0;i<n;i++){
        arr[i]=*sop;
        sop++;
    }
    out(arr,n);
    max(arr,n);

    return 0;
}