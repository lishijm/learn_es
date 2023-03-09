#include<stdio.h>
#include<pthread.h>
#include<string.h>

char buffer[20]={0};

void *threadf1(void *arg){
    if(NULL==arg){
        return (void*)NULL;
    }
    strcpy(buffer,(char *)arg);
    printf("thread1=%s\n",buffer);
    pthread_exit("thread1_exit");
}
void *threadf2(void *arg){
    printf("thread2=%s\n",buffer);
    pthread_exit("thread2_exit");
}

int main(){
    pthread_t pthid1=-1;
    pthread_t pthid2=-1;
    char *str="sssstr";
    if(0!=(pthread_create(&pthid1,NULL,threadf1,str))){
        printf("creat pth1 err\n");
        return -1;
    }
    if(0!=(pthread_create(&pthid2,NULL,threadf2,NULL))){
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