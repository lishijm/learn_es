#ifndef _LINK_H_
#define _LINK_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int data_type;

typedef struct linknode{
    data_type data;
    struct linknode *next;
};

#endif