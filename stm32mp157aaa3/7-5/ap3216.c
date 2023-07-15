#include "ap3216.h"

#define SDA_OUT (GPIOF->MODER=(GPIOF->MODER & ~(3<<30)) | (1<<30))
#define SDA_IN (GPIOF->MODER=GPIOF->MODER & ~(3<<30))

#define SCL_H (GPIOF->ODR=GPIOF->ODR | (1<<14));
#define SCL_L (GPIOF->ODR=GPIOF->ODR & ~(1<<14));

#define SDA_H (GPIOF->ODR=GPIOF->ODR | (1<<15));
#define SDA_L (GPIOF->ODR=GPIOF->ODR & ~(1<<15));

#define READ_SDA (GPIOF->IDR & (1<<15))

extern void delay_ms(int ms);
extern void printf (const char *fmt, ...);

void delay(){
    int i=1000;
    while(i){
        i--;
    }
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
        SCL_H; //开始传输数据
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
    delay_ms(150);
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

void iic_ap3216_write(unsigned char reg,char data){
    iic_start();
    iic_tx_byte(0x1E<<1);
    iic_tx_byte(reg);
    iic_tx_byte(data);
    iic_stop();
}

unsigned char iic_ap3216_read(){
    unsigned char ret=1;
    printf("1\r\n");
    iic_start();
    ret=iic_tx_byte(0x1E<<1);
    if(ret==1){
        printf("ra\r\n");
        return 1;
    }
    ret=1;
    ret=iic_tx_byte(0x0E);
    if(ret==1){
        printf("rb\r\n");
        return 1;
    }
    ret=1;
    iic_start();
    ret=iic_tx_byte(0x1E<<1|1);
    if(ret==1){
        printf("rc\r\n");
        return 1;
    }
    ret=iic_rx_byte(1);
    printf("x\r\n");
    return ret;
}

void ap3216_init(){
    unsigned char ret=1;
    iic_start();
    ret=iic_tx_byte(0x1E<<1);
    delay();
    if(ret==1){
        printf("%d i1",ret);
        return ;
    }
    ret=1;
    ret=iic_tx_byte(0x00);
    delay();
    if(ret==1){
        printf("%d i2",ret);
        return ;
    }
    ret=1;
    ret=iic_tx_byte(0x10);
    delay();
    if(ret==1){
        printf("%d i3",ret);
        return ;
    }
    iic_stop();
    delay_ms(15);
}
