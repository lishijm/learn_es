#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[]){

    FILE *in=NULL;
    FILE *out=NULL;
    in=fopen(argv[1],"r");
    out=fopen(argv[2],"w");
    char buf[8];
    
    if(NULL==in){
        puts("open file err.");
    }
    if(NULL==out){
        puts("open file err.");
    }
    
    while(1){
        memset(buf,0,8);
        int r=fread(buf,1,8,in);
        if(r>0){
            fwrite(buf,1,8,out);
        }
        else if(r==0){
            break;
        }

    }
    fclose(in);
    fclose(out);

    return 0;
}