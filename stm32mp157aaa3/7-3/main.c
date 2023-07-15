#include "uart4.h"
#include "i2c.h"

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
    unsigned short ret_val;
    iic_7006_write(0xE6,0xBF);

    while (1){
        ret_val=iic_7006_read(0xE3);
        ret_val=176*ret_val/65536-47;
        printf("tempture = %d\r\n",ret_val);

        ret_val=iic_7006_read(0xE5);
        ret_val=125*ret_val/65536-6;
        printf("relative humidity = %d\r\n",ret_val);
        
        delay_ms(1000);
        iwdg_feed();
    }
}