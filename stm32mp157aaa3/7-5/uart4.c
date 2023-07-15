#include "uart4.h"

void uart_init(){
    GPIOB->MODER=GPIOB->MODER & ~(3<<4);
    GPIOB->MODER=GPIOB->MODER | (2<<4);
    GPIOG->MODER=GPIOG->MODER & ~(3<<22);
    GPIOG->MODER=GPIOG->MODER | (2<<22);

    GPIOB->AFRL=GPIOB->AFRL & ~(15<<8);
    GPIOB->AFRL=GPIOB->AFRL | (8<<8);
    GPIOG->AFRH=GPIOG->AFRH & ~(15<<12);
    GPIOG->AFRH=GPIOG->AFRH | (6<<12);

    UART4->CR1=UART4->CR1 & ~(1<<28); //word legenth
    UART4->CR1=UART4->CR1 & ~(1<<12);
    UART4->CR1=UART4->CR1 & ~(1<<15); //oversample

    UART4->CR2=UART4->CR2 & ~(3<<12);

    UART4->PRESC=0;

    UART4->BRR=555;

    UART4->CR1 = UART4->CR1 | (1 << 3);
	UART4->CR1 = UART4->CR1 | (1 << 2);
	UART4->CR1 = UART4->CR1 | (1 << 0);  //使能uart4 的发  收   使能uart4

}

void send(char ch){
    while(!(UART4->ISR&(1<<6)));
    UART4->TDR=ch;
}

char recv(){
    while(!(UART4->ISR&(1<<5)));
    return UART4->RDR;
}

void __uart_puts(char *p)
{
	while(*p)
	{
		send(*p);
		p++;
	}
}