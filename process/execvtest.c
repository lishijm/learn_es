#include<stdio.h>

int main(){
    int i;
    char *str[2]={"execv","test"};
    for(i=0;i<2;i++){
        printf("%s\n",str[i]);
    }
    return 0;
}