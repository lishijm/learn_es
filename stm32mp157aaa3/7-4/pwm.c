#include "pwm.h"

void play_stop(){
    TIM4->CCER &= ~(1<<0);
}

void play_tone(int pscset){
    GPIOB->MODER &= ~(3<<12);
    GPIOB->MODER |= (2<<12);

    GPIOB->AFRL &= ~(0xF<<24);
    GPIOB->AFRL |= (2<<24);

    RCC->MP_APB1ENSETR |= (1<<2);

    TIM4->PSC=pscset-1;
    TIM4->ARR=640;
    TIM4->CCR1=320;
    TIM4->CCMR1 &= ~(1<<16);
    TIM4->CCMR1 &= ~(7<<4);
    TIM4->CCMR1 |= (6<<4);
    TIM4->CCMR1 |= (1<<3);
    TIM4->CCMR1 &= ~(3<<0);

    TIM4->CCER |= (1<<0);

    TIM4->CR1 |= (1<<7);
    TIM4->CR1 |= (1<<0);
}
