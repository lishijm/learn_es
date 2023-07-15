#ifndef LCD_H
#define LCD_H

#include <stdint.h>

extern uint8_t ni1[4][32];
void lcd_init(void);
void lcd_clear(uint16_t color);
uint16_t lcd_color(uint8_t red, uint8_t green, uint8_t blue);
void lcd_drawimage(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint16_t* image);
void lcd_drawtext8x16(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc, uint8_t* font);
void lcd_drawstringlower(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc, char* s);
void lcd_drawname(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc);
void lcd_drawni(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc);
void lcd_drawfu(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc);
void lcd_drawwendu(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc);
void lcd_drawnum(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc, uint8_t num);
void lcd_drawmid(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc);
void lcd_drawtext16x16(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc, uint8_t* font);
void lcd_region(uint8_t xbegin, uint8_t xend, uint8_t ybegin, uint8_t yend);
void lcd_drawtext32x32(uint8_t x, uint8_t y, uint16_t fc, uint16_t bc, uint8_t* font);
#endif
