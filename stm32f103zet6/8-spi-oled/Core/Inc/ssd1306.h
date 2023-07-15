#ifndef __SSD1306_H_
#define __SSD1306_H_

#include "main.h"
#include "spi.h"

void ssd1306_spi_init(void);

void ssd1306_spi_send_data_arr(uint32_t data_num);

#endif
