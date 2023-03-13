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

int main(){
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
    shmdt(shmaddr1);
    shmdt(shmaddr2);
    shmctl(shmid1,IPC_RMID,0);
    shmctl(shmid2,IPC_RMID,0);
    return 0;
}