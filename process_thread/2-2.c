#include<stdio.h>
#include<pthread.h>
void *threadf(){
    printf("thread\n");
}

int main(){
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadf,NULL);
    pthread_join(pthid,NULL);//阻塞，等待线程退出。
    //int pthread_join(pthread_t thread, void **retval);
    //pthread_join(线程ID，指向线程退出状态值的指针);
    printf("process\n");
    return 0;
}