#include<stdio.h>
#include<string.h>
int main(){

    char str[10]="1234";
    //printf("%ld\n",strlen(str));
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    /*for(i=0;i<10;i++){
        if(str[i]=='\0'){
            break;
        }
        p++;
    }*/
    printf("%d",i);
    //printf("%ld\n",sizeof(str));
    
    return 0;
}