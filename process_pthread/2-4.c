#include<stdio.h>
#include<pthread.h>
void *threadf(void *arg){
    if(NULL==arg){
        return (void*)NULL;
    }
    int b=*(int *)arg;
    printf("arg=%d\n",b);
    printf("thread\n");
    pthread_exit("thread_exit");
    //void pthread_exit(void *retval);
    //参数为返回值，可用pthread_join接收
}

int main(){
    pthread_t pthid;
    int a=103;
    //int *pa=&a;
    pthread_create(&pthid,NULL,threadf,(void *)&a);
    //pthread_create(&pthid,NULL,threadf,(void *)pa);
    char *pthstate=NULL;
    pthread_join(pthid,(void*)&pthstate);//阻塞，等待线程退出。
    //int pthread_join(pthread_t thread, void **retval);
    //pthread_join(线程ID，指向线程退出状态值的指针);
    printf("pthstate=%s\r\n",pthstate);
    printf("process\n");
    return 0;
}