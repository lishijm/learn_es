#include "uart4.h"
#include "led.h"
#include "adc.h"

extern void printf (const char *fmt, ...);

void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}

int main(){
    char ch;
    
    led_init();
    uart_init();
    adc_init();

    while (1){
        ch=recv();
        if(ch=='a'){
            led_onE10();
            led_onE8();
            led_onF10();        
        }
        if(ch=='b'){
            led_offE8();
            led_offF10();
            led_offE10();
        }
        if(ch=='c'){
            printf("channel 1 = %d\r\n",get_value(1));
        }
        if(ch=='d'){
            printf("channel 0 = %d\r\n",get_value(0));
        }
    }
}