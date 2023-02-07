#include<stdio.h>
int main(){
    int n,x;
    scanf("%d",&n);
    int trg[n][n];
    int i,j;

    for(i=0;i<n;i++){
        trg[i][0]=1;
    }
    for(i=1;i<n;i++){
        for(j=1;j<i;j++){
            trg[i][j]=trg[i-1][j-1]+trg[i-1][j];
        }
        trg[i][j]=1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%d\t",trg[i][j]);
        }
        printf("\n");
    }

    return 0;
}