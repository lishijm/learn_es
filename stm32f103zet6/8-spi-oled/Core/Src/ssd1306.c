#include "ssd1306.h"

uint8_t OLED_InitCmd[26]={
    0xAE,0x20,0x10,0xB0,0xC8,0x40,                              
    0x81,0x7F,0xA1,0xA6,0xA8,0x3F,
    0xA4,0xD3,0x00,0xD5,0xF0,0xD9,
    0x22,0xDA,0x12,0xDB,0x20,0x8D,
    0x14,0xAF,
};

void ssd1306_spi_init(void){
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
    uint8_t count_send;
    for(count_send=0;count_send<26;count_send++){
        HAL_SPI_Transmit(&hspi1,&OLED_InitCmd[count_send],1,HAL_MAX_DELAY);
    }
}

void ssd1306_spi_send_data_arr(uint32_t data_num){
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
    uint32_t count_send;
    uint8_t data=0xFF;
    for(count_send=0;count_send<data_num;count_send++){
        HAL_SPI_Transmit(&hspi1,&data,1,HAL_MAX_DELAY);
    }
}
