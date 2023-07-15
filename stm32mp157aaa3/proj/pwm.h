#ifndef _PWM_H_
#define _PWM_H_

#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_rcc.h"
#include "common/include/stm32mp1xx_tim.h" 

void fan_off();

void fan_on();

void play_stop();

void play_tone(int pscset);

#endif