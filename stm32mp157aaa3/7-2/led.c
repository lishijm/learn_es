#include "led.h"

void delayms(int t)
{
	int i;
	for( ; t>0; t--)
	{
		for(i = 0; i < 1000; i++)
		{
		}
	}
}
void led_init(void){
	RCC_AHB4_ENSETR |= (0x1<<5);
	GPIOF->MODER = GPIOF->MODER & ~(3  << 20);
	GPIOF->MODER = GPIOF->MODER | ( 1 << 20);
	GPIOF->OTYPER = GPIOF->OTYPER & ~(1  << 10);
	GPIOF->OSPEEDR &=(~(0x3<<20));
	GPIOE->PUPDR &=(~(0x3<<20));
}
void led_onE10(void){
	GPIOE->ODR = GPIOE->ODR | ( 1 << 10); 
}

void led_offE10(void){
	GPIOE->ODR = GPIOE->ODR & ~( 1 << 10); 
}

void led_onF10(void){
	GPIOF->ODR = GPIOF->ODR | ( 1 << 10); 
}

void led_offF10(void){
	GPIOF->ODR = GPIOF->ODR & ~( 1 << 10); 
}

void led_onE8(void){
	GPIOE->ODR = GPIOE->ODR | ( 1 << 8); 
}

void led_offE8(void){
	GPIOE->ODR = GPIOE->ODR & ~( 1 << 8); 
}