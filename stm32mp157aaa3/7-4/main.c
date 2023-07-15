#include "pwm.h"
#include "uart4.h"

void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}

int main(){
    char key;
    while (1){
        key=recv();
        if(key=='s'){
            play_stop();
            play_tone(382);
            delay_ms(100);
            play_stop();
        }
        if(key=='d'){
            play_stop();
            play_tone(340);
            delay_ms(100);
            play_stop();
        }
        if(key=='f'){
            play_stop();
            play_tone(303);
            delay_ms(100);
            play_stop();
        }
        if(key=='g'){
            play_stop();
            play_tone(286);
            delay_ms(100);
            play_stop();
        }
        if(key=='h'){
            play_stop();
            play_tone(255);
            delay_ms(100);
            play_stop();
        }
        if(key=='j'){
            play_stop();
            play_tone(227);
            delay_ms(100);
            play_stop();
        }
        if(key=='k'){
            play_stop();
            play_tone(202);
            delay_ms(100);
            play_stop();
        }
    }
}