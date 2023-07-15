#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int listel;

typedef struct information{
    listel arr[5];
    int count; 
} list;

int del(list *p,int pos);
int insert(list *p,int pos,listel posco);
int output(list *p);

#endif