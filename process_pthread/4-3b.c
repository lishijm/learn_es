#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(){
    sem_t *sem1=sem_open("sem1n",O_CREAT,0666,1);
    sem_t *sem2=sem_open("sem2n",O_CREAT,0666,0); 
    while(1){
        sem_wait(sem2);
        printf("43b\n");
        sleep(1);
        sem_post(sem1);
    }
    return 0;
}