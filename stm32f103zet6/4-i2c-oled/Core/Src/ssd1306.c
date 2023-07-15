#include "ssd1306.h"

void delay_us(uint16_t delayusn){
    __HAL_TIM_SET_COUNTER(&htim1,0);
    __HAL_TIM_ENABLE(&htim1);
    while(__HAL_TIM_GET_COUNTER(&htim1)<delayusn){
        
    }
    __HAL_TIM_DISABLE(&htim1);
}

const unsigned char OLED_InitCmd[26]={
    0xAE,
    0x20,
    0x10,
    0xB0,
    0xC8,
    0x40,                              
    0x81,
    0x7F,
    0xA1,
    0xA6,
    0xA8,
    0x3F,
    0xA4,
    0xD3,
    0x00,
    0xD5,
    0xF0,
    0xD9,
    0x22,
    0xDA,
    0x12,
    0xDB,
    0x20,
    0x8D,
    0x14,
    0xAF,   
};

#define SDAOUT (GPIO_ChangeMode(GPIO_PIN_1,GPIO_MODE_OUTPUT_PP))
#define SDAIN (GPIO_ChangeMode(GPIO_PIN_1,GPIO_MODE_INPUT))
#define SCLH (HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET))
#define SCLL (HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET))
#define SDAH (HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET))
#define SDAL (HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET))
#define READSDA (GPIOC->IDR&(1<<1))
#define I2CDELAY (delay_us(1))

#define SSD1306_ADDRESS 0x78

void i2c_start(){
    SDAOUT;
    SDAH;
    SCLH;
    I2CDELAY;
    SDAL;
    I2CDELAY;
    SCLL;
}

void i2c_stop(){
    SDAOUT;
    SCLL;
    SDAL;
    I2CDELAY;
    SCLH;
    I2CDELAY;
    SDAH;
    I2CDELAY;
}

uint8_t i2c_tx_byte(uint8_t data){
    uint8_t bitcount;
    uint8_t ack=0;
    SDAOUT;
    for(bitcount=0;bitcount<8;bitcount++){
        SCLL;
        I2CDELAY;
        if(data&(1<<7)){
            SDAH;
        }
        else{
            SDAL;
        }
        SCLH;
        I2CDELAY;
        data=data<<1;
    }
    SCLL;
    SDAH;
    SDAIN;
    SCLH;
    if(READSDA){
        ack=1;
    }
    else{
        ack=0;
    }
    SCLL;
    return ack;
}

void ssd1306_i2c_write(uint8_t ctrl_byte,uint8_t data_byte){
    i2c_start();
    i2c_tx_byte(SSD1306_ADDRESS);
    i2c_tx_byte(ctrl_byte);
    i2c_tx_byte(data_byte);
    i2c_stop();
}

void ssd1306_i2c_init(void){
    uint8_t cmdcount;
    i2c_start();
    i2c_tx_byte(SSD1306_ADDRESS);
    i2c_tx_byte(0x00);
    for(cmdcount=0;cmdcount<26;cmdcount++){
        i2c_tx_byte(OLED_InitCmd[cmdcount]);
    }
    i2c_stop();
}

void ssd1306_i2c_send_data_arr(uint32_t data_num){
    uint16_t count_send;
    i2c_start();
    i2c_tx_byte(SSD1306_ADDRESS);
    i2c_tx_byte(0x40);
    for(count_send=0;count_send<data_num;count_send++){
        i2c_tx_byte(0xFF);
    }
    i2c_stop();
}
