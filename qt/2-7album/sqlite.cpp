#include "sqlite.h"

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

void sql_opr::close(const string pathname){
    int ret=sqlite3_close(dbp);
    if(ret!=0){
        cout<<"db close err"<<endl;
    }
}
