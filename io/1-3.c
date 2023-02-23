#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[]){
    FILE *fp=NULL;
    fp=fopen(argv[1],"r");
    
    fseek(fp,0,SEEK_END);
    printf("the size of %s is %ld byte\n",argv[1],ftell(fp));

    return 0;
}