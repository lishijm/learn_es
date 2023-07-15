#include "led.h"

void led_init(void){

	GPIOE->MODER = GPIOE->MODER & ~(3  << 20);
	GPIOE->MODER = GPIOE->MODER | ( 1 << 20);
	GPIOE->OTYPER = GPIOE->OTYPER & ~(1  << 10);
	GPIOE->OSPEEDR &=(~(0x3<<20));
	GPIOE->PUPDR &=(~(0x3<<20));

	RCC->MP_AHB4ENSETR |= (0x1<<5);
	GPIOF->MODER = GPIOF->MODER & ~(3  << 20);
	GPIOF->MODER = GPIOF->MODER | ( 1 << 20);
	GPIOF->OTYPER = GPIOF->OTYPER & ~(1  << 10);
	GPIOF->OSPEEDR &=(~(0x3<<20));
	GPIOF->PUPDR &=(~(0x3<<20));

	GPIOE->MODER = GPIOE->MODER & ~(3  << 16);
	GPIOE->MODER = GPIOE->MODER | ( 1 << 16);
	GPIOE->OTYPER = GPIOE->OTYPER & ~(1  << 8);
	GPIOE->OSPEEDR &=(~(0x3<<16));
	GPIOE->PUPDR &=(~(0x3<<16));
	
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