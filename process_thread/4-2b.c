//消息队列
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>

typedef struct node{
    long msgn;
    char content[20];
} nodes;

int main(){
    key_t key;
    key=ftok(".",25);
    if(key==-1){
        printf("ftok err\n");
        return -1;
    }
    int msgid=msgget(key,IPC_CREAT|0666);
    if(-1==msgid){
        printf("msgget err\n");
        return -1;
    }
    nodes msg[5];
    int i;
    for(i=0;i<5;i++){
        msgrcv(msgid,(void *)&msg[i],20,5,0);
        //msgctl(msgid,IPC_STAT,(struct msqid_ds *)&msg);
        printf("%s",msg[i].content);
    }
    msgctl(msgid,IPC_RMID,0);
    return 0;
}