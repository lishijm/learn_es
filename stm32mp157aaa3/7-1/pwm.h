#ifndef _PWM_H_
#define _PWM_H_

#include "stm32mp1xx_gpio.h"
#include "stm32mp1xx_rcc.h"
#include "stm32mp1xx_tim.h" 

void pwm_init();

void play_stop();

void play_tone(int pscset);

#endif