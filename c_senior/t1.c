#include<stdio.h>
int main(){
    FILE *fp;
    if((fp=fopen("1.txt","r"))==NULL){
        perror("faile to fopen");
        return -1;
    }
    fclose(fp);
    
    return 0;
}