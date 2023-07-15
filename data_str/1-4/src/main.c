#include "../include/20.h"

int main(){
    char words[1024];
    gets(words);
    link *phead=NULL;

    link *ptmp=(link *)malloc(sizeof(link));
    ptmp->data=1;
    ptmp->next=NULL;
    phead=ptmp;
    int i=0;
    while(words[i]!='\0'){
        link *a=(link *)malloc(sizeof(link));
        a->data=words[i];
        a->next=NULL;

        ptmp->next=a;
        ptmp=ptmp->next;
        i++;
    }
    
    insetrlink(phead);
    printlink(phead);


    return 0;
}