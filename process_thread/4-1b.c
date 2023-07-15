#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int shmid,i;
	char *shmaddr;
	key_t key;
	key = ftok(".",23);
	shmid=shmget(key,1024*4,0);
    shmaddr=shmat(shmid,0,0);
    for(i=0;i<15;i++){
        printf("%d",*((int *)shmaddr+i));
    }
    shmdt(shmaddr);
    shmctl(shmid,IPC_RMID,0);
    return 0;
}