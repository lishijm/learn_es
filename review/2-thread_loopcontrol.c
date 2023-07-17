//多线程实现按键检测停止开始训话和退出程序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_t thread;
int stopstoring=0;

void *printhreadf(){
    while(1){
        if(stopstoring==1){
            break;
        }
        printf("thread\r\n");
    }
}

int main(){
    int loop_val;
    pthread_create(&thread,NULL,printhreadf,NULL);

    char key_input;
    while (1){
        scanf("%c",&key_input);
        pthread_mutex_lock(&mutex);
        if(key_input=='a'){
            stopstoring=1;
        }
        else if(key_input=='b'){
            pthread_create(&thread,NULL,printhreadf,NULL);
            stopstoring=0;
        }
        else if(key_input=='c'){
            stopstoring=1;
            break;
        }
        pthread_mutex_unlock(&mutex);
    
    }
    printf("while ending\r\n");
    pthread_join(thread,NULL);

    pthread_mutex_destroy(&mutex);
    
    return 0;
}