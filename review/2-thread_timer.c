#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

void *threadf(){
    printf("thread\r\n");
}

int main(){
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadf,NULL);
    pthread_join(pthid,NULL);
    printf("main\r\n");

    return 0;
}