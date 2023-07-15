#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>

#define DB_FILE "stu.db"

int do_insert(sqlite3 *db){
    // 输入id
	int id;
	printf("input id:");
	scanf("%d", &id);
	getchar();

	// 输入name
	char name[32] = {0};
	printf("input name:");
	scanf("%s", name);
	getchar();

	// 输入score
	int score;
	printf("input score:");
	scanf("%d", &score);
	getchar();

    char sql[128]={0};
    sprintf(sql,"insert into stu values(%dd,'%s',%d);",id,name,score);
    char *errmsg=NULL;
    int ret=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error,%s\n",errmsg);
        
    }
    sqlite3_free(errmsg);
    return -1;
}

int main(){
    //打开数据库
    sqlite3 *db=NULL;
    int ret = sqlite3_open(DB_FILE,&db);
    if(ret!=SQLITE_OK){
        printf("sqlite3_open error,%s\n",sqlite3_errmsg(db));
        return -1;
    }
    //创建表
    char sql[]="create table if not esists stu(id integer primary key not null,name text,score integer);";
    char *errmsg=NULL;
    ret=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec error,%s\n",errmsg);
        sqlite3_free(errmsg);
        return -1;
    }
    //插入，更新，查询，删除表记录
    int op;
    while(1){
        menu();
        printf("please input:");
        scnaf("%d",&op);
        getchar();
        switch(op){
            case 1:
                do_insert(db);
        }
    }
    return 0;
}