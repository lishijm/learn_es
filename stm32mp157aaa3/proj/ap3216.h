#ifndef _AP3216_H_
#define _AP3216_H_

#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_rcc.h"

void iic_ap3216_write(unsigned char reg,char data);

unsigned char iic_ap3216_read();

void ap3216_init();

#endif