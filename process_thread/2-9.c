//sem_wait(sem_t) 参数遇到>0继续，参数-1；遇到0阻塞。
//sem_post(sem_t) 参数+1。
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<semaphore.h>

sem_t sema;
sem_t semb;

void *threadf1(void *arg){
    int i=20;
    while(i--){
        sem_wait(&sema);
        printf("pht1 ");
        sleep(1);//制造混乱
        sem_post(&semb);
    }
}
void *threadf2(void *arg){
    int i=20;
    while(i--){
        sem_wait(&semb);
        printf("pht2\n");
        //sleep(1);
        sem_post(&sema);
    }
}

int main(){
    pthread_t pthid1=-1;
    pthread_t pthid2=-1;
    sem_init(&sema,0,1);
    sem_init(&semb,0,0);
    if(0!=(pthread_create(&pthid1,NULL,threadf1,NULL))){
        printf("creat pth1 err\n");
        return -1;
    }
    if(0!=(pthread_create(&pthid2,NULL,threadf2,NULL))){
        printf("creat pth2 err\n");
        return -1;
    }
    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    printf("process\n");
    return 0;
}