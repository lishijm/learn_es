#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sqlite3.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sstream>
using namespace std;

#define SERV_PORT 5050
#define SIGNIN "signin"
#define ALOGIN "a_login"
#define NLOGIN "n_login"
#define QUIT "quit"
#define AD_VIEW "a_view"
#define SEARCH "search"
#define DB_FILE "proj.db"

typedef struct logstruct{
    char *name;
    char *passwd;
    int result;
} logs;

typedef struct tabstruct{
    char **result;
    int row,column;
} tables;

int scommon_back(void *backp,int f_num,char **f_value,char **f_name){
    *(int *)backp=1;
    return 0;
}

int common_search(const string name,sqlite3 *dbp){
    string cssql="select * from user_information where name='"+name+"'";
    char *errmsg=nullptr;
    int flagsi=0;
    int *flagp=&flagsi;
    int ret=sqlite3_exec(dbp,cssql.data(),scommon_back,flagp,&errmsg);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error, %s\n", errmsg);
        sqlite3_free(errmsg);
        return flagsi;
    }
    return flagsi;
}

int lgs_back(void *backp,int f_num,char **f_value,char **f_name){
    logs *lgp=(logs *)backp;
    cout<<f_value[2]<<endl;
    cout<<lgp->passwd<<endl;
    cout<<strlen(f_value[1])<<" "<<strlen(lgp->passwd)<<endl;
    if(0==strncmp(lgp->passwd,f_value[2],strlen(f_value[2]))){
        lgp->result=1;
        return 0;
    }
    else{
        lgp->result=0;
        return 0;
    }
}

bool login_search(const string name,const string passwd,sqlite3 *dbp){
    cout<<name<<passwd<<endl;
    logs *lp=(logs *)malloc(sizeof(logs));
    memset(lp,0,sizeof(lp));
    lp->name=(char *)name.data();
    lp->passwd=(char *)passwd.data();
    string cssql="select * from user_information where name='"+name+"'";
    char *errmsg=nullptr;
    int ret=sqlite3_exec(dbp,cssql.data(),lgs_back,lp,&errmsg);
    if(ret!=SQLITE_OK){
        sqlite3_free(errmsg);
    }
    if(lp->result==1){
        free(lp);
        cout<<"login ok"<<endl;
        return true;
    }
    else{
        free(lp);
        cout<<"login fales"<<endl;
        return false;
    }
}

class sql_opr{
private:
    void exec(const string sql);
    sqlite3 *dbp;
public:
    void open(const string pathname);
    bool close();
    void create(const string sql);
    bool signin(const string sql,const string name);
    bool login(const string name,const string passwd);
    void table(const string sql,tables *tab);
    bool search(const string name);
};

bool sql_opr::search(const string name){
    int ret=common_search(name,dbp);
    if(ret==1){
        return true;
    }
    else{
        cout<<"user has not exist"<<endl;
        return false;
    }
}

void sql_opr::create(const string sql){
    this->exec(sql);
}

bool sql_opr::signin(const string sql,const string name){
    int ret=common_search(name,dbp);
    if(ret==0){
        exec(sql);
        cout<<"sign in ok"<<endl;
        return true;
    }
    else{
        cout<<"user name has exist"<<endl;
        return false;
    }
}

bool sql_opr::login(const string name,const string passwd){
    int ret=common_search(name,dbp);
    if(ret==0){
        cout<<"user has not exist"<<endl;
        return false;
    }
    else if(ret==1){
        if(login_search(name,passwd,dbp)){
            time_t now;
            int rt=time(&now);
            if(rt==-1){
                return false;
            }
            string time=ctime(&now);
            cout<<time<<endl;
            string time_sql="insert into "+name+" values(NULL,'"+time+"');";
            cout<<time_sql<<endl;
            this->exec(time_sql);

            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void sql_opr::open(const string pathname){
    int ret=sqlite3_open(pathname.data(),&dbp);
    if(ret!=SQLITE_OK){
        string err=sqlite3_errmsg(dbp);
        cout<<"sqlte3_open error"+err<<endl;
        return ;
    }
    else{
        cout<<"database open ok."<<endl;
    }
}

void sql_opr::exec(const string sql){
    char *errmsg=nullptr;
    int ret=sqlite3_exec(dbp,sql.data(),nullptr,nullptr,&errmsg);
    if(ret!=SQLITE_OK){
        string err=errmsg;
        cout<<"sqlite3_exec error,"+err<<endl;
        return ;
    }
    else{
        cout<<"exec ok"<<endl;
    }
}

void sql_opr::table(const string sql,tables *tab){
    
    char *errmsg=nullptr;
    
    int ret=sqlite3_get_table(dbp,sql.data(),&tab->result,&tab->row,&tab->column,&errmsg);
    if(ret!=SQLITE_OK){
        string err=errmsg;
        cout<<"sqlite3_get_table error,"+err<<endl;
        sqlite3_free(errmsg);
        return ;
    }

    return ;
}

class user_opr{
protected:
    sql_opr appdb;
    string dbpath;
public:
    void start(const string &dbpath);
};

void user_opr::start(const string &dbpath){
    this->appdb.open(dbpath);
    string crsql="create table if not exists user_information(id integer primary key not null,name text,passwd text,type text);";
    this->appdb.create(crsql);
}

class normal_user_opr:virtual public user_opr{
public:
    void signin(int conFd);
    void login(int conFd);
};

void normal_user_opr::login(int conFd){
    char namestr[10]={0},passwdstr[10]={0},buf[1024];
    int state=1;
    memset(buf,0,sizeof(buf));
    recv(conFd,buf,sizeof(buf),0);
    sscanf(buf,"%d\n%s\n%s",&state,namestr,passwdstr);
    if(state==0){
        return ;
    }

    string name=namestr;
    string passwd=passwdstr;
#if 0
    int sizehead;
    memset(buf,0,sizeof(buf));
    recv(conFd,buf,sizeof(buf),0);
    sscanf(buf,"#%d#",&sizehead);
    printf("%d\n",sizehead);

    int ret=0,count=0;
    string filename;
    filename=name+".jpg";
    FILE *fp;

    fp=fopen(filename.data(),"wb");
    for(;;){
        memset(buf,0,sizeof(buf));
        ret=recv(conFd,buf,sizeof(buf),0);
        fwrite(buf,1,sizeof(buf),fp);
        cout<<ret<<endl;
        count+=ret;
        if(ret==0){
            break;
        }
    }
    fclose(fp);
#endif
    if(this->appdb.login(name,passwd)){
        memset(buf,0,sizeof(buf));
        strcpy(buf, "#1#");
        usleep(500);
        send(conFd,buf,sizeof(buf),0);
#if 1
        int sizehead;
        memset(buf,0,sizeof(buf));
        recv(conFd,buf,sizeof(buf),0);
        sscanf(buf,"#%d#",&sizehead);
        printf("%d\n",sizehead);

        int ret=0,count=0;
        string filename;
        filename=name+".jpg";
        FILE *fp;

        fp=fopen(filename.data(),"wb+");
        for(;;){
            memset(buf,0,sizeof(buf));
            ret=recv(conFd,buf,sizeof(buf),0);
            fwrite(buf,1,sizeof(buf),fp);
            cout<<ret<<endl;
            count+=ret;
            if(ret==0){
                break;
            }
        }
        fclose(fp);
#endif
    }
    else{
        memset(buf,0,sizeof(buf));
        strcpy(buf, "#0#");
        usleep(500);
        send(conFd,buf,sizeof(buf),0);
    }
}

void normal_user_opr::signin(int conFd){
    char namestr[10]={0},passwdstr[10]={0},buf[BUFSIZ];
    int state=1;
    memset(buf,0,sizeof(buf));
    recv(conFd,buf,sizeof(buf),0);
    sscanf(buf,"%d\n%s\n%s",&state,namestr,passwdstr);
    if(state==0){
        return ;
    }
    string user_name=namestr;
    string user_passwd=passwdstr;
    cout<<user_name<<" "<<user_passwd<<endl;
    string user_type="a";
    string insql="insert into user_information values(NULL,'"+user_name+"','"+user_passwd+"','"+user_type+"');";
    cout<<insql<<endl;
    string result;

    if(this->appdb.signin(insql,user_name)){
        result="#1#";
        send(conFd,result.data(),strlen(result.data()),0);
        insql.clear();
        insql="create table if not exists "+user_name+"(id integer primary key not null,time text);";
        this->appdb.create(insql);
    }
    else{
        result="#0#";
        send(conFd,result.data(),strlen(result.data()),0);
    }
}


class admin_user_opr:virtual public user_opr{
public:
    void login(int conFd);
    void view_table(int conFd);
    void search(int conFd);
};

void admin_user_opr::login(int conFd){
    char namestr[10]={0},passwdstr[10]={0},buf[BUFSIZ];
    int state=1;
    memset(buf,0,sizeof(buf));
    recv(conFd,buf,sizeof(buf),0);
    sscanf(buf,"%d\n%s\n%s",&state,namestr,passwdstr);
    if(state==0){
        return ;
    }
    string name=namestr;
    string passwd=passwdstr;
    string admin_name="admin";
    string admin_passwd="root";

    if(admin_name==name&&admin_passwd==passwd){
        memset(buf,0,sizeof(buf));
        strcpy(buf,"#1#");
        send(conFd,buf,strlen(buf),0);
    }
    else{
        memset(buf,0,sizeof(buf));
        strcpy(buf,"#0#");
        send(conFd,buf,strlen(buf),0);
    }
}

void admin_user_opr::view_table(int conFd){

    tables *tab=nullptr;
    tab=(tables *)malloc(sizeof(tables));
    string sql="select *from user_information";
    this->appdb.table(sql,tab);
    
    int i,j;
    printf("%d %d\n",tab->row,tab->column);
    char re[128]={0};
    ostringstream fre_info;
    fre_info<<"#"<<tab->row<<"#"<<tab->column<<"#";
    string re_info=fre_info.str();
    send(conFd,re_info.data(),strlen(re_info.data()),0);
    puts("send head ok");
    
    char buf[20];
    int index=tab->column;
    for(i=0;i<tab->row;i++){
        for(j=0;j<tab->column;j++){
            memset(buf,0,sizeof(buf));
            usleep(50000);
            strcpy(buf,tab->result[index++]);
            cout<<buf<<endl;
            send(conFd,buf,strlen(buf),0);
        }
    }
    sqlite3_free_table(tab->result);
    free(tab);

    return ;
}

void admin_user_opr::search(int conFd){
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    recv(conFd,buf,sizeof(buf),0);
    string table_name=buf;
    if(this->appdb.search(table_name)){
        memset(buf,0,sizeof(buf));
        strcpy(buf,"#1#");
        send(conFd,buf,strlen(buf),0);

        tables *tab=nullptr;
        tab=(tables *)malloc(sizeof(tables));
        string sql="select *from "+table_name;
        this->appdb.table(sql,tab);

        int i,j;
        printf("%d %d\n",tab->row,tab->column);
        char re[128]={0};
        ostringstream fre_info;
        fre_info<<"#"<<tab->row<<"#"<<tab->column<<"#";
        string re_info=fre_info.str();
        usleep(50000);
        send(conFd,re_info.data(),strlen(re_info.data()),0);
        cout<<re_info.data()<<endl;
        puts("send head ok");
        
        int index=tab->column;
        for(i=0;i<tab->row;i++){
            for(j=0;j<tab->column;j++){
                usleep(50000);
                cout<<tab->result[index]<<" "<<endl;
                strcpy(buf,tab->result[index++]);
                send(conFd,buf,strlen(buf)+1,0);
            }
        }
        puts("a");
        sqlite3_free_table(tab->result);
        free(tab);
    }
    else{
        memset(buf,0,sizeof(buf));
        strcpy(buf,"#0#");
        send(conFd,buf,sizeof(buf),0);
    }

    return ;
}

class aplc:public normal_user_opr,public admin_user_opr{
public:
    void run(int conFd);
};

void aplc::run(int conFd){
    this->start(DB_FILE);
    string cmd;
    bool state=true;
    int ret;
    cout<<sizeof(cmd.data())<<endl;
    for(;;){
        memset(cmd.data(),0,sizeof(cmd.data()));
        ret=recv(conFd,cmd.data(),sizeof(cmd.data()),0);
        cout<<cmd.data()<<endl;
        if(0==strncmp(cmd.data(),SIGNIN,strlen(SIGNIN))){
            this->signin(conFd);
        }
        if(0==strncmp(cmd.data(),ALOGIN,strlen(ALOGIN))){
            admin_user_opr::login(conFd);
        }
        if(0==strncmp(cmd.data(),NLOGIN,strlen(NLOGIN))){
            normal_user_opr::login(conFd);
        }
        if(0==strncmp(cmd.data(),AD_VIEW,strlen(AD_VIEW))){
            this->view_table(conFd);
        }
        if(0==strncmp(cmd.data(),SEARCH,strlen(SEARCH))){
            this->search(conFd);
        }
        if(ret==0||0==strncmp(cmd.data(),QUIT,strlen(QUIT))){
            cout<<"quit";
            break;
        }
    }
    close(conFd);
    return ;
}

int main(){
    
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
    int ret=bind(listenFd,(struct sockaddr *)&sin,sizeof(sin));
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

    int conFd;
    bool state;
    for(;;){
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
            aplc aplc1;
            aplc1.run(conFd);
            exit(0);
        }
        else{
            close(conFd);
        }
    }

    close(listenFd);
    return 0;
}