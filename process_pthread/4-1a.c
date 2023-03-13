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
    int buf[15];
    for(i=0;i<15;i++){
        buf[i]=10;
    }
	key_t key;
	key = ftok(".",23);
	shmid=shmget(key,1024*4,IPC_CREAT|0666);
    shmaddr=shmat(shmid,0,0);
    memcpy((int *)shmaddr,buf,sizeof(buf));
    sleep(10);
    shmdt(shmaddr);
    shmctl(shmid,IPC_RMID,0);

    return 0;
}