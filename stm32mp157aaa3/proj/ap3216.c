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

void iic_ap3216_delay(){
    int i=1000;
    while(i){
        i--;
    }
}

void iic_ap3216_start(){
    SDA_OUT;
    SDA_H;
    SCL_H;
    iic_ap3216_delay();
    SDA_L;
    iic_ap3216_delay();
    SCL_L;
}

void iic_ap3216_stop(){
    SDA_OUT;
    SCL_L;
    SDA_L;
    iic_ap3216_delay();
    SCL_H;
    iic_ap3216_delay();
    SDA_H;
    iic_ap3216_delay();
}

char iic_ap3216_tx_byte(unsigned char data){
    int i;
    char ack;
    
    SDA_OUT;
    for(i=0;i<8;i++){
        SCL_L;
        iic_ap3216_delay();
        if(data&(1<<7)){
            SDA_H;
        }
        else{
            SDA_L;
        }
        SCL_H; //开始传输数据
        iic_ap3216_delay();
        iic_ap3216_delay();
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

unsigned char iic_ap3216_rx_byte(char ack){
    delay_ms(150);
    unsigned char data=0;
    int i;
    SCL_L;
    SDA_H;
    SDA_IN;
    for(i=0;i<8;i++){
        iic_ap3216_delay();
        SCL_H;
        iic_ap3216_delay();
        iic_ap3216_delay();
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
    iic_ap3216_delay();
    SCL_L;

    return data;
}

void iic_ap3216_write(unsigned char reg,char data){
    iic_ap3216_start();
    iic_ap3216_tx_byte(0x1E<<1);
    iic_ap3216_tx_byte(reg);
    iic_ap3216_tx_byte(data);
    iic_ap3216_stop();
}

unsigned char iic_ap3216_read(){
    unsigned char ret=1;
    iic_ap3216_start();
    ret=iic_ap3216_tx_byte(0x1E<<1);
    if(ret==1){
        printf("ra\r\n");
        return 1;
    }
    ret=1;
    ret=iic_ap3216_tx_byte(0x0E);
    if(ret==1){
        printf("rb\r\n");
        return 1;
    }
    ret=1;
    iic_ap3216_start();
    ret=iic_ap3216_tx_byte(0x1E<<1|1);
    if(ret==1){
        printf("rc\r\n");
        return 1;
    }
    ret=iic_ap3216_rx_byte(1);
    return ret;
}

void ap3216_init(){
    unsigned char ret=1;
    iic_ap3216_start();
    ret=iic_ap3216_tx_byte(0x1E<<1);
    iic_ap3216_delay();
    if(ret==1){
        printf("%d i1",ret);
        return ;
    }
    ret=1;
    ret=iic_ap3216_tx_byte(0x00);
    iic_ap3216_delay();
    if(ret==1){
        printf("%d i2",ret);
        return ;
    }
    ret=1;
    ret=iic_ap3216_tx_byte(0x10);
    iic_ap3216_delay();
    if(ret==1){
        printf("%d i3",ret);
        return ;
    }
    iic_ap3216_stop();
    delay_ms(15);
}
