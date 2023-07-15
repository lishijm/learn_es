#ifndef _LED_H_                                      
#define _LED_H_

#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_rcc.h"

void led_init(void);

void led_onE10(void);

void led_offE10(void);

void led_onF10(void);

void led_offF10(void);

void led_onE8(void);

void led_offE8(void);

#endif