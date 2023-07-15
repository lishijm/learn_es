#include "../include/ser.h"

int main()
{
    //打开数据库
    sqlite3 *db=NULL;
    int ret=sqlite3_open(DB_FILE,&db);
    if(ret!=SQLITE_OK){
        printf("sqlite3_opene error,%s\n",sqlite3_errmsg(db));
        return -1;
    }

    //创建表
    char sql[]="create table if not exists student_information(id integer primary key not null,name text,class integer,time text);";
    char *errmsgs=NULL;
    ret=sqlite3_exec(db,sql,NULL,NULL,&errmsgs);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error,%s\n",errmsgs);
        return -1;
    }
    
    //创建监听套接字
    int listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd<0){
        perror("socker error");
        exit(1);
    }
    printf("socket ok\n");
    
    //端口复用快速恢复
    int on=1;
    setsockopt(listenFd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    
    //套接字绑定
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=htons(INADDR_ANY);
    ret=bind(listenFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("bind error");
        exit(1);
    }
    printf("bind ok\n");
    
    //套接字监听
    ret=listen(listenFd,5);
    if(ret<0){
        perror("listen error");
        exit(1);
    }
    printf("listen ok\n");
    
    //客户端并发接入
    int conFd;
    while(1){
        //连接套接字
        conFd=accept(listenFd,NULL,NULL);
        if(conFd<0){
            perror("accept error");
            exit(1);
        }
        printf("accept ok\n");
        pid_t pid;
        pid=fork();
        if(pid<0){
            printf("fork error\n");
            exit(1);
        }
        if(pid==0){
            close(listenFd);
            client_com(conFd,db);
            exit(0);
        }
        else{
            close(conFd);
        }
    }

    close(listenFd);
    return 0;
}