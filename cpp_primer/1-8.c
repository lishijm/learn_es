#include<stdio.h>
void swap(int *ap,int *bp)
{
    int tmp;
    tmp=*ap;
    *ap=*bp;
    *bp=tmp;
}

int main()
{
    int a=5,b=10;
    swap(&a,&b);
    printf("%d %d\n",a,b);

    return 0;
}