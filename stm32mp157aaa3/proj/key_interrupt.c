#include "key_interrupt.h"
extern void printf(const char *fmt, ...);
/*
 * KEY2按键接到PF7引脚之上
 * */ 
#if 1
void hal_gpio_init(void)
{
	// 使能GPIOF组的时钟使能， 在  RCC_MP_AHB4ENSETR 
	RCC->MP_AHB4ENSETR |= (0x1 << 5);	
	// 设置PF7引脚为输入功能 
	GPIOF->MODER &= (~(0x3 << 18));
	// 禁止PF7引脚的上拉和下拉功能
	GPIOF->PUPDR &= (~(0x3 << 18));
}

/*
 * PF7引脚对应的外部中断事件是EXTI[7]
 * 对应着Event Input 7 
 * 具体的外设和EXTI对应的关系在21.3章节 
 * 按键中断设置为下降沿触发中断事件的检测
 * */
void hal_exti_init(void)
{
	// 设置为下降沿触发选择寄存器
	EXTI->FTSR1 |= (0x1 << 9);
	printf("EXTI->FTSR1 addr = %x = %x\n", &EXTI->FTSR1, EXTI->FTSR1);
	// 设置外部中断选择寄存器 连接到PF7上 
	EXTI->EXTICR3 &= (~(0xFF << 8));
	EXTI->EXTICR3 |= (0x5 << 8);
	printf("EXTI->EXTICR2 addr = %x = %x\n", &EXTI->EXTICR2, EXTI->EXTICR2);
	// 设置EXTI CPU1唤醒中断屏蔽寄存器 
	EXTI->C1IMR1 |= (0x1 << 9);
	printf("EXTI->C1IMR1 addr = %x = %x\n", &EXTI->C1IMR1, EXTI->C1IMR1);
	// 设置EXTI CPU1唤醒事件屏蔽寄存器 
	EXTI->C1EMR1 |= (0x1 << 9);
	printf("EXTI->C1EMR1 addr = %x = %x\n", &EXTI->C1EMR1, EXTI->C1EMR1);
}
/*
 * PF7引脚属于EXTI7 
 * EXTI7 对应的中断ID为 97 
 * 对应关系在芯片手册的21.2章节
 * */ 

void hal_gicd_init(void)
{
	// 设置中断使能寄存器  GICD_ISENABLER3[1]        使能97 号中断
	GICD->ISENABLER[3] |= (0x1 << 3);
	printf("GICD->ISENABLER addr = %x = %x\n", GICD->ISENABLER, GICD->ISENABLER[3]);
	// 设置中断 的优先级  GICD_IPRIORITYR24[15:11] 设置为24
	GICD->IPRIORITYR[24] &= (~(0x1F << 27));
	GICD->IPRIORITYR[24] |= (24 << 27);
	printf("GICD->IPRIORITYR addr = %x = %x\n", GICD->IPRIORITYR, GICD->IPRIORITYR[24]);
	// 设置中断目标分配寄存器   GICD_ITARGETSR24[9:8]  设置为0x3 
//	GICD->ITARGETSR[24] |= (0x3 << 24); 
	GICD->ITARGETSR[24] |= (0x1 << 24);                       //zyb ???????????????？*******

	printf("zyb ****  *** GICD->ITARGETSR addr = %x = %x\n", GICD->ITARGETSR, GICD->ITARGETSR[24]);
	// 设置GICC层全局使能寄存器 
	GICD->CTRL |= (0x1 << 0);
	printf("GICD->CTRL addr = %x = %x\n", &GICD->CTRL, GICD->CTRL);
	
}
void hal_gicc_init(void)
{
	// 设置GICC层 中断全局使能寄存器
	GICC->CTRL |= (0x1 << 0);
	printf("GICC->CTRL addr = %x = %x\n", &GICC->CTRL, GICC->CTRL);
	// 设置GICC层 中断屏蔽寄存器
	GICC->PMR |= (0x1F << 3);
	printf("GICC->PMR addr = %x = %x\n", &GICC->PMR, GICC->PMR);

}
#else
void hal_gpio_init(void)
{
	// 使能GPIOF组的时钟使能， 在  RCC_MP_AHB4ENSETR 
	RCC->MP_AHB4ENSETR |= (0x1 << 5);	
	// 设置PF7引脚为输入功能 
	GPIOF->MODER &= (~(0x3 << 14));
	// 禁止PF7引脚的上拉和下拉功能
	GPIOF->PUPDR &= (~(0x3 << 14));
}

/*
 * PF7引脚对应的外部中断事件是EXTI[7]
 * 对应着Event Input 7 
 * 具体的外设和EXTI对应的关系在21.3章节 
 * 按键中断设置为下降沿触发中断事件的检测
 * */
void hal_exti_init(void)
{
	// 设置为下降沿触发选择寄存器
	EXTI->FTSR1 |= (0x1 << 7);
	printf("EXTI->FTSR1 addr = %x = %x\n", &EXTI->FTSR1, EXTI->FTSR1);
	// 设置外部中断选择寄存器 连接到PF7上 
	EXTI->EXTICR2 &= (~(0xFF << 24));
	EXTI->EXTICR2 |= (0x5 << 24);
	printf("EXTI->EXTICR2 addr = %x = %x\n", &EXTI->EXTICR2, EXTI->EXTICR2);
	// 设置EXTI CPU1唤醒中断屏蔽寄存器 
	EXTI->C1IMR1 |= (0x1 << 7);
	printf("EXTI->C1IMR1 addr = %x = %x\n", &EXTI->C1IMR1, EXTI->C1IMR1);
	// 设置EXTI CPU1唤醒事件屏蔽寄存器 
	EXTI->C1EMR1 |= (0x1 << 7);
	printf("EXTI->C1EMR1 addr = %x = %x\n", &EXTI->C1EMR1, EXTI->C1EMR1);
}
/*
 * PF7引脚属于EXTI7 
 * EXTI7 对应的中断ID为 97 
 * 对应关系在芯片手册的21.2章节
 * */ 

void hal_gicd_init(void)
{
	// 设置中断使能寄存器  GICD_ISENABLER3[1]
	GICD->ISENABLER[3] |= (0x1 << 1);
	printf("GICD->ISENABLER addr = %x = %x\n", GICD->ISENABLER, GICD->ISENABLER[3]);
	// 设置中断 的优先级  GICD_IPRIORITYR24[15:11] 设置为24
	GICD->IPRIORITYR[24] &= (~(0x1F << 11));
	GICD->IPRIORITYR[24] |= (24 << 11);
	printf("GICD->IPRIORITYR addr = %x = %x\n", GICD->IPRIORITYR, GICD->IPRIORITYR[24]);
	// 设置中断目标分配寄存器   GICD_ITARGETSR24[9:8]  设置为0x3 
//	GICD->ITARGETSR[24] |= (0x3 << 8);
	GICD->ITARGETSR[24] &= ~(3 << 8);                       //zyb ???????????????？*******
 
	GICD->ITARGETSR[24] |= (1 << 8);                       //zyb ???????????????？*******

	printf("zyb ****  *** GICD->ITARGETSR addr = %x = %x\n", GICD->ITARGETSR, GICD->ITARGETSR[24]);
	// 设置GICC层全局使能寄存器 
	GICD->CTRL &= ~(3 << 0);
	GICD->CTRL |= (1 << 0);
	printf("GICD->CTRL addr = %x = %x\n", &GICD->CTRL, GICD->CTRL);
	GICD->IGROUPR[3] &= ~(1<<1); //ZYB
}
void hal_gicc_init(void)
{
	// 设置GICC层 中断全局使能寄存器
	GICC->CTRL &= ~(3 << 0);
	
	GICC->CTRL |= (1 << 0);
	
	
	//GICC->CTRL |= (1 << 3);
	//GICC->CTRL |= (1 << 5);
	

	
	printf("GICC->CTRL addr = %x = %x\n", &GICC->CTRL, GICC->CTRL);
	// 设置GICC层 中断屏蔽寄存器
	GICC->PMR |= (0x1F << 3);
	printf("GICC->PMR addr = %x = %x\n", &GICC->PMR, GICC->PMR);

}

#endif

