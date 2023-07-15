#include<stdio.h>
#include<pthread.h>
void *threadf1(void *arg){
    if(NULL==arg){
        return (void*)NULL;
    }
    int b=*(int *)arg;
    printf("arg=%d\n",b);
    printf("thread1\n");
    pthread_exit("thread1_exit");
    //void pthread_exit(void *retval);
    //参数为返回值，可用pthread_join接收
}
void *threadf2(void *arg){
    if(NULL==arg){
        return (void*)NULL;
    }
    printf("arg=%d\n",*(int *)arg);
    printf("thread2\n");
    pthread_exit("thread2_exit");
    //void pthread_exit(void *retval);
    //参数为返回值，可用pthread_join接收
}

int main(){
    pthread_t pthid1=-1;
    pthread_t pthid2=-1;
    int a=1,b=2;
    if(0!=(pthread_create(&pthid1,NULL,threadf1,(void *)&a))){
        printf("creat pth1 err\n");
        return -1;
    }
    if(0!=(pthread_create(&pthid2,NULL,threadf2,(void *)&b))){
        printf("creat pth2 err\n");
        return -1;
    }
    char *pthstate1=NULL;
    char *pthstate2=NULL;
    pthread_join(pthid1,(void*)&pthstate1);
    pthread_join(pthid2,(void*)&pthstate2);
    printf("pthstate=%s\r\n",pthstate1);
    printf("pthstate=%s\r\n",pthstate2);
    printf("process\n");
    return 0;
}