#ifndef LCD_H
#define LCD_H

#include <stdint.h>

void lcd_init(void);
void lcd_region(uint8_t xbegin, uint8_t xend, uint8_t ybegin, uint8_t yend);
void lcd_clear(uint16_t color);
void lcd_drawimage(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

#endif
