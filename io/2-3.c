#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[]){
    int i;
    int fd1=open(argv[1],O_RDWR,0644);
    char buffer[10];

    int rr=read(fd1,buffer,10);
    for(i=0;i<10;i++){
        buffer[i]=buffer[i]*(-1);
    }
    lseek(fd1,0,SEEK_SET);
    write(fd1,buffer,rr);
    close(fd1);
    
    return 0;
}