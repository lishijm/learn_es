#ifndef _LED_H_                                      
#define _LED_H_

#include "stm32mp1xx_gpio.h"

#define RCC_AHB4_ENSETR (*(volatile unsigned int*)0x50000A28)

void led_init(void);

void led_onE10(void);
void led_offE10(void);

void led_onF10(void);
void led_offF10(void);

void led_onE8(void);
void led_offE8(void);

#endif