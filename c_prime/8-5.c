#include<stdio.h>
int main(){
    int a[2];
    int *p;
    p=a;
    scanf("%d%d",p,(p+1));
    printf("%d %d\n",*p,*(p+1));
    
    return 0;
}