#ifndef _UART4_H_
#define _UART4_H_

#include "stm32mp1xx_uart.h"
#include "stm32mp1xx_gpio.h"

void uart_init();

void send(char ch);

char recv();

void __uart_puts(char *p);

#endif