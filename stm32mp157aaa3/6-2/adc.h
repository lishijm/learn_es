#ifndef _ADC_H_
#define _ADC_H_

#include "stm32mp1xx_adc.h"
#include "stm32mp1xx_rcc.h"

void adc_init();

unsigned short get_value(unsigned char channel);

#endif