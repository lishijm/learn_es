#ifndef _20_H_
#define _20_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char datat;

typedef struct linknode{
    datat data;
    struct linknode *next;
} link;

link *crlink(void);
int printlink(link *phead);
int insetrlink(link *phead);

#endif // !_20_H_