#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SEM_READ 0
#define SEM_WRITE 1

union semun
{
    int val;
};

void P_op(int index,int semID)
{
    struct sembuf sop;
    sop.sem_num=index;
    sop.sem_op=-1;
    sop.sem_flg=0;
    semop(semID,&sop,1);
}

void V_op(int index,int semID)
{
    struct sembuf sop;
    sop.sem_num=index;
    sop.sem_op=1;
    sop.sem_flg=0;
    semop(semID,&sop,1);
}

int main()
{
    key_t key=-1;
    pid_t pid=-1;
    int semID=-1;
    int shmID=-1;

    char *shamaddr=NULL;
    key=ftok(".",123);
    if(-1==key)
    {
        printf("ftok error!-------\r\n");
        return -1;
    }
    printf("1:ftok ok!-----------\r\n");
    semID=semget(key,2,IPC_CREAT|0755);
    if(semID<0)
    {
        printf("semget error!-------\r\n");
        return -1;
    }
    printf("2:semget ok!------------\r\n");
    shmID=shmget(key,128,IPC_CREAT|0755);
    if(shmID<0)
    {
        printf("shmget error!------\r\n");
        return -1;
    }
    printf("3: shmget ok!------------\r\n");

    union semun  m;
    m.val=0;
    semctl(semID,SEM_READ,SETVAL,m);

    m.val=1;
    semctl(semID,SEM_WRITE,SETVAL,m);

    pid=fork();
    if(-1==pid)
    {
        printf("fork error!------------\r\n");
        return -1;
    }
    if(0==pid)
    {
        while(1)
        {
            shamaddr=(char *)shmat(shmID,NULL,0);
            P_op(SEM_READ,semID);
            printf("get data:%s\r\n",shamaddr);
            V_op(SEM_WRITE,semID);
        }
    }
    else
    {
        while(1)
        {
            shamaddr=(char *)shmat(shmID,NULL,0);
            P_op(SEM_WRITE,semID);
            printf("input data:\r\n");
            fgets(shamaddr,32,stdin);
            V_op(SEM_READ,semID);
        }
    }
    return 0;
}