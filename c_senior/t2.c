#include<stdio.h>
int main(){
    int a;
    while(1){
        a=fgets(stdin);
        if((a>='0')&&(a<='9'))fputs(a,stdout);
        if(a=='\n') break;
    }

    return 0;
}