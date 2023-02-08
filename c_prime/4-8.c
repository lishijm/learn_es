#include<stdio.h>
#define MIN(a,b) a>b?b:a
int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",MIN(a,b));

    return 0;
}