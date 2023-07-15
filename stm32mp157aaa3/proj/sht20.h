#ifndef _SHT20_H_
#define _SHT20_H_

#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_rcc.h"

void  iic_init();

void iic_start();

void iic_stop();

char iic_tx_byte(unsigned char data);

unsigned char iic_rx_byte(char ack);

void iic_sht20_write(unsigned char cmd,char data);

unsigned short iic_sht20_read(unsigned char cmd);

#endif