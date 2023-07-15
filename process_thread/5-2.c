#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

union semun{
    int val;
};

void pop(int index,int semid){
    struct sembuf sop;
    sop.sem_num=index;
    sop.sem_op=-1;
    sop.sem_flg=0;
    semop(semid,&sop,1);
}

void vop(int index,int semid){
    struct sembuf sop;
    sop.sem_num=index;
    sop.sem_op=1;
    sop.sem_flg=0;
    semop(semid,&sop,1);
}

int main(){
    key_t key=ftok(".",20);
    if(-1==key){
        printf("ftok error\n");
        return -1;
    }
    printf("ftok ok\n");
    int semid=semget(key,128,IPC_CREAT|0755);
    if(semid<0){
        printf("semget error\n");
        return -1;
    }
    printf("semget ok\n");
    union semun m;
    m.val=0;
    semctl(semid,0,SETVAL,m);

    m.val=1;
    semctl(semid,1,SETVAL,m);
    
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("fork error\n");
        return -1;
    }
    else if(pid==0){
        while(1){
            pop(0,semid);
            printf("child process\n");
            vop(1,semid);
        }
    }
    else{
        while(1){
            sleep(1);
            pop(1,semid);
            printf("parent process\n");
            vop(0,semid);
        }
    }

    return 0;
}