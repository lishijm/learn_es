#ifndef _SER_H_
#define _SER_H_

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

static int flagsearch;

void push_inf(int,sqlite3 *,int *);
void look_inf(int,sqlite3 *,int *);
int callback(void *,int,char **,char **);
void search_inf(int,sqlite3 *,int *);
void update_inf(int,sqlite3 *,int *);
void del_inf(int,sqlite3 *,int *);
void client_com(int,sqlite3 *);

#endif