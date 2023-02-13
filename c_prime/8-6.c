#include<stdio.h>
int main(){
    int *ip;
    char *cp;
    float *fp;
    double *dp;
    printf("%ld,%ld,%ld,%ld",sizeof(ip),sizeof(cp),sizeof(fp),sizeof(dp));

    return 0;
}