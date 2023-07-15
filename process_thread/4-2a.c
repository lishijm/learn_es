//消息队列,实现异步通信
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
        msg[i].msgn=5;
    }
    char buf[5];
    for(i=0;i<5;i++){
        memset(buf,0,sizeof(buf));
        sprintf(buf,"%d\n",i);
        strcpy(msg[i].content,buf);
    }
    for(i=0;i<5;i++){
        printf("%s",msg[i].content);
    }
    for(i=0;i<5;i++){
        msgsnd(msgid,(void *)&msg[i],20,0);
    }
    //msgctl(msgid,IPC_SET,(struct msqid_ds *)&msg);
    sleep(10);
    msgctl(msgid,IPC_RMID,0);
    return 0;
}