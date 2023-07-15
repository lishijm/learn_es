#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_exti.h"
#include "common/include/stm32mp1xx_gic.h"
#include "pwm.h"

extern void printf(const char *fmt, ...);

void do_irq(void) 
{
	//获取对应的中断的中断号 
	unsigned int irq_num;
	irq_num = GICC->IAR & (0x3FF);
	switch(irq_num){
		case 99:
			play_stop();
			EXTI->FPR1 |= (0x1 << 9);
			// 清除GICD层中断 
			GICD->ICPENDR[3] |= (0x1 << 3);
			break;
		case 98:
			break;

	}
	// 清除GICC层中断
	GICC->EOIR = (GICC->EOIR & (~0x3FF)) | irq_num;

}
