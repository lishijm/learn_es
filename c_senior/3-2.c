#include<stdio.h>
#include<time.h>

int main(){
    clock_t t;
    int i,j,n,tmp;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                tmp=a[j+1];
                a[j+1]=a[j];
                a[j]=tmp;
            }   
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    t = clock();
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
}