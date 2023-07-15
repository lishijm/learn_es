#ifndef _TIM1_H_
#define _TIM1_H_

typedef struct{
    unsigned int CR1;
    unsigned int CR2;
    unsigned int SMCR;
    unsigned int DIER;
    unsigned int SR;
    unsigned int EGR;
    unsigned int CCMR1;
    unsigned int CCMR2;
    unsigned int CCER;
    unsigned int CNT;
    unsigned int PSC;
    unsigned int ARR;
    unsigned int RCR;
    unsigned int CCR1;
    unsigned int CCR2;
    unsigned int CCR3;
    unsigned int CCR4;
    unsigned int BDTR;
    unsigned int DCR;
    unsigned int DMAR;
    unsigned int CCMR3;
    unsigned int CCR5;
    unsigned int CCR6;
    unsigned int TIM1_AF1;
    unsigned int TIM1_AF2;
    unsigned int TIM1_TISEL;
} ac_tim;

#define TIM1 ((volatile ac_tim *)0x44000000)

#endif