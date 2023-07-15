#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sqlite3.h>
#include <time.h>
#include <sys/stat.h>

#define SERV_PORT 5050
#define DB_FILE "student_information.db"
#define PUSH "push"
#define QUIT "quit"
#define LOOK "look"
#define SEARCH "search"
#define UPDATE "update"
#define NAME "name"
#define CLASS "class"
#define DEL "delet"

int flagsearch=0;

void push_inf(int conFd,sqlite3 *db,int *exit)
{
    *exit=0;    
    time_t now;
    int rt=time(&now);
    if(rt==-1){
        return ;
    }
    int id,class;
    char inf[BUFSIZ],name[20];
    char *pt=ctime(&now);

    memset(inf,0,sizeof(inf));
    recv(conFd,inf,sizeof(inf),0);
    sscanf(inf,"#%d#",&id);

    memset(name,0,sizeof(name));
    recv(conFd,name,sizeof(name),0);

    memset(inf,0,sizeof(inf));
    recv(conFd,inf,sizeof(inf),0);
    sscanf(inf,"#%d#",&class);

    printf("%d %s %d %d\n",id,name,class,getpid());

    char sql[128]={0};
    sprintf(sql,"insert into student_information values(%d,'%s',%d,'%s');",id,name,class,pt);
    char *errmsgs=NULL;
    int ret=sqlite3_exec(db,sql,NULL,NULL,&errmsgs);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error,%s\n",errmsgs);
        sqlite3_free(errmsgs);
        return ;
    }
    printf("do_insert success\n");

    int fileFd;
    char filename[9],buf[BUFSIZ];
    memset(filename,0,sizeof(filename));
    sprintf(filename,"%d.jpg",id);
    printf("%s\n",filename);

    int count=0;
    long legnth;
    char sizebuf[BUFSIZ];
    memset(sizebuf,0,sizeof(sizebuf));
    recv(conFd,sizebuf,sizeof(sizebuf),0);
    sscanf(sizebuf,"#%ld#",&legnth);
    printf("%ld\n",legnth);

    if(legnth==0){
        return ;
    }

    fileFd=open(filename,O_WRONLY|O_CREAT,0664);
    while(1){
        memset(buf,0,sizeof(buf));
        ret=recv(conFd,buf,sizeof(buf),0);
        if(ret<0){
            perror("recv error");
            continue;
        }
        if(ret==0){
            *exit=1;
            break;
        }
        write(fileFd,buf,ret);
        count+=ret;
        if(count>=legnth){
            break;
        }
    }
    puts("push ok");
    close(fileFd);

}

void look_inf(int conFd,sqlite3 *db,int *exit)
{
    char **result=NULL;
    int row,column,i,j;
    char *errmsgs=NULL;
    char sql[]="select *from student_information";
    int ret=sqlite3_get_table(db,sql,&result,&row,&column,&errmsgs);
    if(ret!=SQLITE_OK){
        printf("sqlite3_get_table error,%s\n",errmsgs);
        sqlite3_free(errmsgs);
        return ;
    }
    printf("%d %d\n",row,column);
    char re[128]={0};
    sprintf(re,"#%d#%d#",row,column);
    send(conFd,re,sizeof(re),0);
    puts("send head ok");
    char buf[BUFSIZ];
    int index=column;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            usleep(10000);
            strcpy(buf,result[index++]);
            send(conFd,buf,strlen(buf)+1,0);
        }
    }
    sqlite3_free_table(result);
    puts("look ok");
}

int callback(void *conFds,int f_num,char **f_value,char **f_name)
{
    int conFd=*(int *)conFds;
    char buf[10]={0},inf[128],flag[5];
    int i;
    flagsearch=1;
    sprintf(flag,"#%d#",flagsearch);
    send(conFd,flag,sizeof(flag),0);
    usleep(10000);
    sprintf(buf,"#%d#",f_num);
    send(conFd,buf,sizeof(buf),0);
	for(i=0; i<f_num;i++){
        usleep(10000);
        memset(inf,0,sizeof(inf));
        strcpy(inf,f_value[i]);
		send(conFd,inf,sizeof(inf),0);
	}
    int fd;

    return 0;
}

void search_inf(int conFd,sqlite3 *db,int *exit)
{
    flagsearch=0;
    char sinf[12],sql[128]={0},flag[5]={0},filename[20]={0};
    int id;
    recv(conFd,sinf,sizeof(sinf),0);
    sscanf(sinf,"#%d#",&id);
    printf("%d\n",id);

    sprintf(sql,"select * from student_information where id=%d",id);
    char *errmsgs=NULL;
    int ret=sqlite3_exec(db,sql,callback,&conFd,&errmsgs);
    if(flagsearch==0){
        sprintf(flag,"#%d#",flagsearch);
        send(conFd,flag,sizeof(flag),0);
    }
    else if(flagsearch==1){
        sprintf(filename,"%d.jpg",id);
        int fd;
        char size[20],filebuf[BUFSIZ];
        fd=open(filename,O_RDONLY);

        struct stat statbuf;
        stat(filename,&statbuf);
        printf("%ld\n",statbuf.st_size);
        memset(size,0,sizeof(size));
        sprintf(size,"#%ld#",statbuf.st_size);
        usleep(100000);
        
        send(conFd,size,sizeof(size),0);
        usleep(100000);
        
        while(1){
            memset(filebuf,0,sizeof(filebuf));
            ret=read(fd,filebuf,sizeof(filebuf));
            if(ret==0){
                break;
            }
            else{
                send(conFd,filebuf,ret,0);
            }
        }
        close(fd);
    }
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error, %s\n", errmsgs);
        sqlite3_free(errmsgs);
        return ;
    }

    puts("search ok");
}

void update_inf(int conFd,sqlite3 *db,int *exit)
{
    int id,class;
    char name[22]={0},sel[10]={0},idbuf[22]={0},classbuf[22]={0},sql[128]={0};
    recv(conFd,idbuf,sizeof(idbuf),0);
    sscanf(idbuf,"#%d#",&id);
    printf("%d\n",id);
    recv(conFd,sel,sizeof(sel),0);
    if(0==strncasecmp(sel,NAME,strlen(NAME))){
        puts("name");
        recv(conFd,name,sizeof(name),0);
        printf("%s\n",name);
        sprintf(sql,"update student_information set name='%s' where id=%d;",name,id);
        char *errmsgs=NULL;
        int ret=sqlite3_exec(db,sql,NULL,NULL,&errmsgs);
        if(ret<0){
            printf("sqlite3_exec error,%s\n",errmsgs);
            sqlite3_free(errmsgs);
            return ;
        }
    }
    else if(0==strncasecmp(sel,CLASS,strlen(CLASS))){
        puts("class");
        recv(conFd,classbuf,sizeof(classbuf),0);
        sscanf(classbuf,"#%d#",&class);
        sprintf(sql,"update student_information set class=%d where id=%d;",class,id);
        char *errmsgs=NULL;
        int ret=sqlite3_exec(db,sql,NULL,NULL,&errmsgs);
        if(ret<0){
            printf("sqlite3_exec error,%s\n",errmsgs);
            sqlite3_free(errmsgs);
            return ;
        }
    }
    else{
        return ;
    }
    printf("update_inf ok\n");
}

void del_inf(int conFd,sqlite3 *db,int *exit)
{
    int id;
    char idbuf[22]={0};
    recv(conFd,idbuf,sizeof(idbuf),0);
    sscanf(idbuf,"#%d#",&id);
    char sql[128]={0};
    char filere[20]={0};
    sprintf(filere,"%d.jpg",id);
    remove(filere);
    sprintf(sql,"delete from student_information where id=%d;",id);
    char *errmsgs=NULL;
    int ret=sqlite3_exec(db,sql,NULL,NULL,&errmsgs);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error,%s\n",errmsgs);
        sqlite3_free(errmsgs);
        return ;
    }
    printf("del_inf ok\n");
}

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
