#include<stdio.h>

void strfkcat(char *rp1,char *rp2){
    while(*rp1!='\0'){
        rp1++;
    }
    while(*rp2!='\0'){
        *rp1=*rp2;
        rp2++;
        rp1++;
    }
    *rp1='\0';
}
int main(){
    int n;
    scanf("%d",&n);
    char str1[2*n],str2[n];
    scanf("%s",str1);
    scanf("%s",str2);
    strfkcat(str1,str2);
    puts(str1);

    return 0;
}