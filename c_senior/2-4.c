#include<stdio.h>

struct {
    char name[30];
    short s;
    int a;
    float b;
} ss;
union {
    char name[30];
    short s;
    int a;
    float b;
} uu;

int main(){
    printf("%ld",sizeof(ss));
    printf("%ld",sizeof(uu));
}