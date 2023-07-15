#ifndef __SSD1306_H_
#define __SSD1306_H_
#include "main.h"
#include "tim.h"
#include "gpio.h"

void delay_us(uint16_t delayusn);

void ssd1306_i2c_write(uint8_t ctrl_byte,uint8_t data_byte);

void ssd1306_i2c_init(void);

void ssd1306_i2c_send_data_arr(uint32_t data_num);

#endif
