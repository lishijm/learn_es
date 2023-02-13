//homework
#include<stdio.h>
int main(){
    char str1[25]="123456789";
    char str2[25]="987654";
    int i=0,j=0;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i]='\0';

    puts(str1);

    return 0;
}