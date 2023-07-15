#include<stdio.h>
int main(){
    int arr[4]={1,2,3,4};;
    int brr[5][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    int (*p)[4];
    int *ip;
    int i,j,k=0;
    p=&arr;
    ip=arr;
    printf("%p\n",p);
    printf("%p\n",ip);
    for(i=0;i<4;i++){
        printf("%d,",*((*p)+i));
        printf("%d\n",*(ip+i));
    }
    printf("\n");
    p=brr;
    ip=&brr[0][0];
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("%d,",*(*(p+i)+j));
            printf("%d\n",*ip+k);
            printf("%p\n",(*(p+i)+j));
            printf("%p\n",ip+k);
            k++;
        }
    }
}