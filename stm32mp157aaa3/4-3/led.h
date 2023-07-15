#ifndef _LED_H_                                      
#define _LED_H_

typedef struct{                                                
    volatile unsigned int MODER;                               
    volatile unsigned int OTYPER;                              
    volatile unsigned int OSPEEDR;                             
    volatile unsigned int PUPDR;                               
    volatile unsigned int IDR;                                 
    volatile unsigned int ODR;                                 
}GPIO_DEF;

#define GPIOE ((volatile GPIO_DEF *)0x50006000)
#define GPIOF ((volatile GPIO_DEF *)0x50007000)
#define RCC_AHB4_ENSETR (*(volatile unsigned int*)0x50000A28)

#endif