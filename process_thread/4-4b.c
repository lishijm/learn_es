#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include<sys/wait.h>
int main(){
    sem_t *sem1=sem_open("441",O_CREAT,0666,1);
    sem_t *sem2=sem_open("442",O_CREAT,0666,0);
    sem_t *sem3=sem_open("443",O_CREAT,0666,1);
    sem_t *sem4=sem_open("444",O_CREAT,0666,0);
    pid_t pid;
    pid=fork();
    int shmid1,shmid2,write;
	char *shmaddr1,*shmaddr2;
	key_t key1;
    key_t key2;
	key1=ftok(".",30);
    key2=ftok(".",31);
	shmid1=shmget(key1,1024*4,IPC_CREAT|0666);
    shmid2=shmget(key2,1024*4,IPC_CREAT|0666);
    shmaddr1=shmat(shmid1,0,0);
    shmaddr2=shmat(shmid2,0,0);
    if(pid<0){
        printf("fork err\n");
        return -1;
    }
    else if(0==pid){
        while(1){
            puts("2w");
            scanf("%s",shmaddr2);
            if(strcmp(shmaddr2,"quit")==0){
                shmdt(shmaddr1);
                shmdt(shmaddr2);
                shmctl(shmid1,IPC_RMID,0);
                shmctl(shmid2,IPC_RMID,0);
                return 0;
            }
            sem_post(sem4);
        }
        exit(0);
    }
    else if(pid>0){
        while(1){
            puts("2r");
            sem_wait(sem2);
            printf("%s\n",shmaddr1);
        }
    }
    shmdt(shmaddr1);
    shmdt(shmaddr2);
    shmctl(shmid1,IPC_RMID,0);
    shmctl(shmid2,IPC_RMID,0);
    return 0;
}