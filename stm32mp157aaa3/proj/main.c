#include "uart4.h"
#include "sht20.h"
#include "pwm.h"
#include "led.h"
#include "ap3216.h"
#include "key_interrupt.h"
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
    fan_off();
    play_stop();
    led_init();
    uart_init();
    iic_init();
    ap3216_init();
    unsigned short ret_val;
    iic_sht20_write(0xE6,0xBF);
    
    hal_gpio_init();
	hal_exti_init();
	hal_gicd_init();
	hal_gicc_init();


    while (1){
        ret_val=iic_sht20_read(0xE3);
        ret_val=176*ret_val/65536-47;
        printf("tempture = %d\r\n",ret_val);

        if(ret_val>33){
            led_onE10();
            play_tone(99);
        }
        else if(ret_val<30){
            led_onF10();
            play_tone(499);
        }
        else{
            led_offF10();
            led_offE10();
            play_stop();
        }
        ret_val=iic_sht20_read(0xE5);
        ret_val=125*ret_val/65536-6;
        printf("relative humidity = %d\r\n",ret_val);

        if(ret_val>=60){
            fan_on();
        }
        else{
            fan_off();
        }

        iic_ap3216_write(0x00,0x03);
        delay_ms(225);
        ret_val=iic_ap3216_read(0x0E);
        printf("ret = %d\r\n",ret_val);

        if(ret_val>100){
            led_onE8();
        }
        else{
            led_offE8();
        }
        
        delay_ms(5000);
        iwdg_feed();
    }
}