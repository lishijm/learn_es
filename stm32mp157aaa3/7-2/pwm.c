#include "pwm.h"

void pwm_init(){

    RCC->MP_AHB4ENSETR |= (0x1<<5);
    GPIOF->MODER &= ~(3<<20);
    GPIOF->MODER |= (2<<20);
    GPIOF->AFRH &= ~(0xF<<8);
    GPIOF->AFRH |= (1<<8);

    RCC->MP_APB2ENSETR |= (1<<3);

    TIM16->PSC=499;
    TIM16->ARR=640;
    TIM16->CCR1=320;
    TIM16->CCMR1 &= ~(1<<16);
    TIM16->CCMR1 &= ~(7<<4);
    TIM16->CCMR1 |= (6<<4);
    TIM16->CCMR1 |= (1<<3);
    TIM16->CCMR1 &= ~(3<<0);

    TIM16->CCER |= (1<<0);

    TIM16->CR1 |= (1<<7);
    TIM16->CR1 |= (1<<0);
}
