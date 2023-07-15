#include "i2c.h"

//scl pf14
//sda pf15

#define SDA_OUT (GPIOF->MODER=(GPIOF->MODER & ~(3<<30)) | (1<<30))
#define SDA_IN (GPIOF->MODER=GPIOF->MODER & ~(3<<30))

#define SCL_H (GPIOF->ODR=GPIOF->ODR | (1<<14));
#define SCL_L (GPIOF->ODR=GPIOF->ODR & ~(1<<14));

#define SDA_H (GPIOF->ODR=GPIOF->ODR | (1<<15));
#define SDA_L (GPIOF->ODR=GPIOF->ODR & ~(1<<15));

#define READ_SDA (GPIOF->IDR & (1<<15))

static void delay(){
    int i=50000;
    while(i--);
}

void  iic_init(){
    RCC->MP_AHB4ENSETR |= (0x1<<5);
    GPIOF->MODER &= ~(0xF<<28);
    GPIOF->MODER |= (0x5<<28);
    GPIOF->OTYPER &= ~(0x3<<14);
    GPIOF->OSPEEDR |= (0xF<<28);
    GPIOF-> PUPDR &= ~(0xF<<28);

    SDA_H;
    SCL_H;
}

void iic_start(){
    SDA_OUT;
    SDA_H;
    SCL_H;
    delay();
    SDA_L;
    delay();
    SCL_L;
}

void iic_stop(){
    SDA_OUT;
    SCL_L;
    SDA_L;
    delay();
    SCL_H;
    delay();
    SDA_H;
    delay();
}

char iic_tx_byte(unsigned char data){
    int i;
    char ack;
    
    SDA_OUT;
    for(i=0;i<8;i++){
        SCL_L;
        delay();
        if(data&(1<<7)){
            SDA_H;
        }
        else{
            SDA_L;
        }
        SCL_H;
        delay();
        delay();
        data=data<<1;
    }
    SCL_L;
    SDA_H;
    SDA_IN;
    SCL_H;

    if(READ_SDA){
        ack=1;
    }
    else{
        ack=0;
    }

    SCL_L;
    return ack;
}

unsigned char iic_rx_byte(char ack){
    unsigned char data=0;
    int i;
    SCL_L;
    SDA_H;
    SDA_IN;

    for(i=0;i<8;i++){
        delay();
        SCL_H;
        delay();
        delay();
        data=data<<1;
        if(READ_SDA){
            data |= 1;
        }
        SCL_L;
    }
    SDA_OUT;
    if(ack){
        SDA_H;
    }
    else{
        SDA_L;
    }
    SCL_H;
    delay();
    SCL_L;

    return data;
}

void iic_7006_write(unsigned char cmd,char data){
    iic_start();
    iic_tx_byte(0x40<<1);//addres=100 0000b
    iic_tx_byte(cmd);//command table
    iic_tx_byte(data);
    iic_stop();
}

unsigned short iic_7006_read(unsigned char cmd){
    unsigned char ret;
    unsigned short ret_val;
    iic_start();
    iic_tx_byte(0x40<<1);
    iic_tx_byte(cmd);
    iic_start();
    iic_tx_byte((0x40<<1)|1);
    ret=iic_rx_byte(0);
    ret_val=ret;
    ret_val=ret_val<<8;
    ret=iic_rx_byte(1);
    ret_val |= ret;

    return ret_val;
}
