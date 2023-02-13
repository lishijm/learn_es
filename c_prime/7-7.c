#include<stdio.h>
int main(){
    char str[5][20];
    int i;
    for(i=0;i<5;i++){
        gets(&str[i][0]);
    }
    for(i=0;i<5;i++){
        puts(&str[i][0]);
    }
}