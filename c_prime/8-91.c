#include<stdio.h>
int in(int *rp,int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",rp);
        rp++;
    }
}
int sor(int *rp,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(*(rp+j)>*(rp+j+1)){
                temp=*(rp+j+1);
                *(rp+j+1)=*(rp+j);
                *(rp+j)=temp;
            }
        }
    }
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
    int i,n;
    scanf("%d",&n);
    int arr[n];

    in(arr,n);
    sor(arr,n);
    out(arr,n);
    max(arr,n);

    return 0;
}