#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define SERV_PORT 5050
#define PUSH "push"
#define QUIT "quit"
#define LOOK "look"
#define SEARCH "search"
#define UPDATE "update"
#define NAME "name"
#define CLASS "class"
#define DEL "delet"

void img();
void push_inf(int);
void look_inf(int);
void search_inf(int);
void update_inf(int);
void del_inf(int);

#endif