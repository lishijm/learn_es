#ifndef _CLASS_H_
#define _CLASS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[20];
    int age;
    int mark[3];
} stu;

void nsize(stu (*p)[3]);
void avr(stu (*p)[3],int s);
void mark(stu (*p)[3],int s);
void age(stu (*p)[3]);

#endif