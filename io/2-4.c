//统计目录下c和h文件的行数，使用在同目录下，该目录不能有子目录

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>
#include <string.h>

int linum(char *filename){
    int i=0;
    FILE *fp;
    char buffer[1];
    fp=fopen(filename,"r");
    while(feof(fp)==0){
        fread(buffer,1,1,fp);
        if(buffer[0]=='\n'){
            i++;
        }
    }
    fclose(fp);
    
    return ++i;
}

int *flnum(char *path){
    static int line[2];
    char *filep;
    DIR *dir;
    struct dirent *rdir;
    dir=opendir(path);
    
    while((rdir=readdir(dir))!=NULL){
        if(strcmp(strrchr(rdir->d_name,'.'),".c")==0){
            line[0]+=linum(rdir->d_name);
        }
        if(strcmp(strrchr(rdir->d_name,'.'),".h")==0){
            line[1]+=linum(rdir->d_name);
        }
    }

    closedir(dir);
    
    return line;
}

int main(int argc,char *argv[]){
    int *line=flnum(argv[1]);
    printf("%d\n",line[0]);
    printf("%d\n",line[1]);
    return 0;
}