#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,i;
    scanf("%d",&n);
    int *p=(int *)malloc(sizeof(int)*n);
    printf("%p",p);
    /*if(p==NULL){
        printf("err\n");
    }
    memset(p,0,sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    for(i=0;i<n;i++){
        printf("%d",*(p+i));
    }*/

    return 0;
}