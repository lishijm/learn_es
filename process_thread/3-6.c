#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
#include<signal.h>
#include<time.h>

void dae(){
    pid_t pid;
    int i = 0;

    if((pid=fork())==-1){
        printf("Fork error !\n");
        exit(1);
    }
    if(pid!=0){
        exit(0);        //父进程退出
    }
    setsid();           //子进程开启新会话，并成为会话首进程和组长进程
    chdir("/");         //设置工作目录为“/”，所以之后生成的文件也在根目录下
    umask(0);           // 重设文件掩码
    for (;i<getdtablesize();++i){
       close(i);        //关闭打开的文件描述符
    }
}

void timelog(){
    FILE *fp=NULL;
    fp=fopen("test.log","a");

    time_t now;
    int rt=time(&now);
    if(rt==-1){
        fclose(fp);
        printf("time error");
        return ;
    }
    char *pt=ctime(&now);

    fwrite(pt,strlen(pt),1,fp);
    fclose(fp);
    sleep(10);
    return  ;
}

int main(int argc,char *argv[]){
    dae();
    while (1){
        timelog();
    }
    return 0;
}