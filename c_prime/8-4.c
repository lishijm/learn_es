#include<stdio.h>
int *p;
int change(int a,int b){
    int tmp[2];
    tmp[0]=b;
    tmp[1]=a;
    p=tmp;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    change(a,b);
    printf("%d %d\n",*p,*(p+1));
    
    return 0;
}