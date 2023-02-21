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
    for(i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            tmp=a[min];
            a[min]=a[i];
            a[i]=tmp;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    t = clock();
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
}