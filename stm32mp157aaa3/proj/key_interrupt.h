#ifndef __KEY_INTERRUPY_H__
#define __KEY_INTERRUPY_H__

#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_exti.h"
#include "common/include/stm32mp1xx_gic.h"
#include "common/include/stm32mp1xx_rcc.h"

void hal_gpio_init(void);
void hal_exti_init(void);
void hal_gicd_init(void);
void hal_gicc_init(void);


#endif // __KEY_INTERRUPY_H__
