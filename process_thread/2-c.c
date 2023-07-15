//单纯的指针函数就是顺序执行，不会产生竞态
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

//pthread_mutex_t mutex;

void *threadf(void *arg){
    char *p=(char *)arg;
    static char buf[11]={0};
    //不使用静态就可以想象为两个buffer
    int i=0;
    //pthread_mutex_lock(&mutex);
    for(i=0;i<11;i++){
        buf[i]=p[i];
        sleep(1);
    }
    printf("%c %s\n",*(char *)arg,buf);
    //pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t pthid1=-1;
    pthread_t pthid2=-1;
    char str1[]="abcdefghij";
    char str2[]="1234567890";
    threadf((void *)str1);
    threadf((void *)str2);
    printf("process\n");
    return 0;
}