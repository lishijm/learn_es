#include "../include/ser.h"

void client_com(int conFd,sqlite3 *db)
{
    char selbuf[128]={0};
    int sel=0,flag=1,exit,ret;
    while(1){
        ret=recv(conFd,selbuf,sizeof(selbuf),0);
        printf("%s\n",selbuf);
        if(0==strncasecmp(selbuf,PUSH,strlen(PUSH))){
            push_inf(conFd,db,&exit);
        }
        if(0==strncasecmp(selbuf,LOOK,strlen(LOOK))){
            look_inf(conFd,db,&exit);
        }
        if(0==strncasecmp(selbuf,SEARCH,strlen(SEARCH))){
            search_inf(conFd,db,&exit);
        }
        if(0==strncasecmp(selbuf,UPDATE,strlen(UPDATE))){
            update_inf(conFd,db,&exit);
        }
        if(0==strncasecmp(selbuf,DEL,strlen(DEL))){
            del_inf(conFd,db,&exit);
        }
        if(ret==0||exit==1||0==strncasecmp(selbuf,QUIT,strlen(QUIT))){
            break;
        }
    }
    close(conFd);
    return ;
}