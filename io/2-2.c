#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[]){

    int fd1=open(argv[1],O_RDONLY,0644);
    int fd2=open(argv[2],O_WRONLY|O_CREAT,0644);

    char buffer[1024];
    while(1){
        int rr=read(fd1,buffer,sizeof(buffer));
        if(rr==0){
            break;
        }
        else{
            write(fd2,buffer,rr);
        }
        
    }
    close(fd1);
    close(fd2);

    return 0;
}