#include<stdio.h>

int main(void) 
{
    #ifdef __cplusplus
    printf("g++\n");
    #else
    printf("gcc\n");
    #endif
}