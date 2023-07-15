#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

pthread_mutex_t mutex;

void *threadf(void *arg){
    char *p=(char *)arg;
    static char buf[11]={0};
    int i=0;
    pthread_mutex_lock(&mutex);
    for(i=0;i<11;i++){
        buf[i]=p[i];
        usleep(500);
    }
    printf("%s\n",buf);
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t pthid1=-1;
    pthread_t pthid2=-1;
    char str1[]="abcdefghij";
    char str2[]="1234567890";
    pthread_mutex_init(&mutex,NULL);
    if(0!=(pthread_create(&pthid1,NULL,threadf,(void *)str1))){
        printf("creat pth1 err\n");
        return -1;
    }
    if(0!=(pthread_create(&pthid2,NULL,threadf,(void *)str2))){
        printf("creat pth2 err\n");
        return -1;
    }
    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    printf("process\n");
    return 0;
}