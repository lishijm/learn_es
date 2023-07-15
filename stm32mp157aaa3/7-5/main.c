#include "uart4.h"
#include "ap3216.h"

extern void printf (const char *fmt, ...);

typedef struct{
    unsigned int KR;
} iwdgs;


#define IWDGREG ((volatile iwdgs *)(0x5a002000))
#define IWDGREG2 ((volatile iwdgs *)(0x5c003000))

void iwdg_feed(){
    IWDGREG->KR=0xAAAA;
    IWDGREG2->KR=0xAAAA;
}

void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}

int main(){
    uart_init();
    iic_init();
    ap3216_init();
    unsigned char ret_val;

    while (1){
        iic_ap3216_write(0x00,0x03);
        delay_ms(225);
        ret_val=iic_ap3216_read(0x0E);
        printf("ret = %d\r\n",ret_val);
        delay_ms(2000);
        iwdg_feed();
    }
}