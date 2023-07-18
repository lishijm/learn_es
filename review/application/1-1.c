//子进程继承父进程缓冲区

#include <stdio.h>
#include <unistd.h>

#define BUFFERMODE 0

int main(){
    int i;
#if BUFFERMODE
    for(i=0;i<2;i++){
        fork();
        printf("* %d",getpid());
    }
#endif

#if !BUFFERMODE
    for(i=0;i<2;i++){
        fork();
        printf("* %d\n",getpid());
    }
#endif


    return 0;
}