#ifndef _FIND_H_
#define _FIND_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int data;

typedef struct list{
    int count;
    data arr[20];
} list;

list *crlist(void);
int find(list *p,int fn);

#endif