#include "led.h"
#include "pwm.h"

void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}

int main(){
    while (1){
        pwm_init();
        delay_ms(1000);
    }
}