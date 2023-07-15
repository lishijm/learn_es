#include<stdio.h>
#include<string.h>
int main(){
    char str1[10]="123456";
    char str2[10]="123";
    int i=0;
    //strcpy(str1,str2);
    while(str2[i]!='\0'){
        str1[i]=str2[i];
        i++;
    }
    str1[i]=str2[i];

    puts(str1);
}