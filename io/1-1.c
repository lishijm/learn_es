#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    if(argc!=2){
        puts("usgae:./a.out filename");
    }
    FILE *fp=NULL;
    char buf[8];
    fp=fopen(argv[1],"r");

    if(NULL==fp){
        puts("open file err.");
    }
    
    while(1){
        memset(buf,0,8);
        int r=fread(buf,1,8,fp);
        if(r>0){
            printf("%s",buf);
        }
        else if(r==0){
            break;
        }

    }
    fclose(fp);

    return 0;
}