#ifndef _UART4_H_
#define _UART4_H_
typedef struct {
	unsigned int  MODER;
	unsigned int OTYPER; 
	unsigned int OSPEEDER;
	unsigned int  PUPDR;
	unsigned int IDR; 
	unsigned int ODR;
	unsigned int BSRR;
	unsigned int LCKR;
	unsigned int AFRL;
    unsigned int AFRH;
}GPIO_DEF;

typedef struct {
	unsigned int  CR1;
    unsigned int  CR2;
    unsigned int  CR3;
    unsigned int  BRR;
    unsigned int  GTPR;
    unsigned int  RTOR;
    unsigned int  RQR;
    unsigned int  ISR;
    unsigned int  ICR;
    unsigned int  RDR;
    unsigned int  TDR;
    unsigned int  PRESC;
    unsigned int  HWCFGR;
    unsigned int  VERR;
    unsigned int  IPIDR;
    unsigned int  SIDR;
}USART_DEF;

#define GPIOB ((volatile GPIO_DEF *)0x50003000)
#define GPIOG ((volatile GPIO_DEF *)0x50008000)
#define UART4 ((volatile USART_DEF *)0X40010000)

void uart_init();

void send(char ch);

char recv();

#endif