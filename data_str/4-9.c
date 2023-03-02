#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int datat;   //int -->  datat

typedef struct arrs{
	datat data[5];
	int count;
} ars;

ars *crqe(void){
	ars *pq = NULL;
	pq = (ars *)malloc(sizeof(ars));
	memset(pq, 0, sizeof(ars));
	return pq;
}

int main(){
    ars *p=NULL;
    p=(ars *)malloc(sizeof(ars));
    
    return 0;
}