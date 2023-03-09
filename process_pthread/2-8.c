#include<stdio.h>
#include<pthread.h>
#include<string.h>

void *threadf1(void *arg){
    printf("thread1=%s\n",(char *)arg);
    return arg;
}
void *threadf2(void *arg){
    printf("thread2=%s\n",(char *)arg);
}

int main(){
    pthread_t pthid1=-1;
    pthread_t pthid2=-1;
    char *str="sssssstr";
    if(0!=(pthread_create(&pthid1,NULL,threadf1,str))){
        printf("creat pth1 err\n");
        return -1;
    }
    char *buffer=threadf1(str);
    if(0!=(pthread_create(&pthid2,NULL,threadf2,buffer))){
        printf("creat pth2 err\n");
        return -1;
    }
    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    printf("process\n");
    return 0;
}