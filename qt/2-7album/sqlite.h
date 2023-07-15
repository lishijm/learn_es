#ifndef SQLITE_H
#define SQLITE_H

#include<string>
#include<iostream>
#include<string.h>
#include<time.h>
#include"sqlite3.h"

typedef struct logstruct{
    char *name;
    char *passwd;
    int result;
} logs;

typedef struct tabstruct{
    char **result;
    int row,column;
} tables;

using namespace std;
class sql_opr{
private:
    void exec(const string sql);
    sqlite3 *dbp;
public:
    void open(const string pathname);
    void close(const string pathname);
    void create(const string sql);
    bool signin(const string sql,const string name);
    bool login(const string name,const string passwd);
};

#endif // SQLITE_H
