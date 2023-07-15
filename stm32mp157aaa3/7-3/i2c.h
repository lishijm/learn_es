#ifndef _I2C_H_
#define _I2C_H_

#include "common/include/stm32mp1xx_gpio.h"
#include "common/include/stm32mp1xx_rcc.h"

void  iic_init();

void iic_start();

void iic_stop();

char iic_tx_byte(unsigned char data);

unsigned char iic_rx_byte(char ack);

void iic_7006_write(unsigned char cmd,char data);

unsigned short iic_7006_read(unsigned char cmd);

#endif