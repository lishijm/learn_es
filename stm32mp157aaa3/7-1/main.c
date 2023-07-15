#include "pwm.h"

void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}

int main(){
    pwm_init();
    delay_ms(1000);
    while (1){
        delay_ms(1000);
        play_stop();
        play_tone(400);
        delay_ms(1000);
        play_stop();
        play_tone(330);
        delay_ms(1000);
        play_stop();
        play_tone(268);
    }
}