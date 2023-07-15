#include <stdio.h>

int main(void) 
{ 
    long sizechar=sizeof('a');
    if(sizechar==1){
        printf("g++\n");
    }
    else if(sizechar==4){
        printf("gcc\n");
    }
    return 0; 
}