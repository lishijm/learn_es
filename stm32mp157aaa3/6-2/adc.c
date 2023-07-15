#include "adc.h"

extern void delay_ms(int ms);
void adc_init(void){
    
    RCC->MP_AHB2ENSETR = RCC->MP_AHB2ENSETR | ( 1 << 5); //enable adc 时钟
    RCC->ADCCKSELR = RCC->ADCCKSELR & ~(3<<0);
    RCC->ADCCKSELR = RCC->ADCCKSELR | (1<<0);  //adc 时钟来源于接口总线 

    ADC_COMMON->CCR = ADC_COMMON->CCR & ~(0xf << 18);
    ADC_COMMON->CCR = ADC_COMMON->CCR | (0x1 << 18);//adc 时钟 2 分频 


    ADC->CR = ADC->CR & ~( 1 << 29); //禁止deep power模式
    ADC->CR = ADC->CR | ( 1 << 28);//使能adc 整流稳压 

    delay_ms(10);
    ADC->CR = ADC->CR & ~( 1 << 30);//单端
    ADC->CR = ADC->CR | ( 1 << 16);//线性
    ADC->CR = ADC->CR | ( 1 << 31); //开始校准 
    while( (ADC->CR & ( 1 << 31))) ;


    ADC->CFGR1 = ADC->CFGR1 & ~(1 << 13); //单次转换模式 
    ADC->CFGR1 = ADC->CFGR1 & ~(3 << 10); //软件触发adc 转换
    ADC->CFGR1 = ADC->CFGR1 & ~(7 << 2);//分辨率 16



    ADC->CFGR2 = ADC->CFGR2 & ~(0x3ff << 16);//不过样采集 
    ADC->CFGR2 = ADC->CFGR2 & ~(0xf << 28);//数据靠右对齐 


    ADC->SQR1 = ADC->SQR1 & ~(0xf << 0); //转换的总通道数 是 1
    ADC->SQR1 = ADC->SQR1 & ~(0x1f << 6); 
    ADC->SQR1 = ADC->SQR1 | (1 << 6);//转换的第一个通道是通道1

    ADC->SMPR1 = ADC->SMPR1 | ( 7 << 3); //采集时间为  810.5个时钟周期

    ADC->PCSEL = ADC->PCSEL | ( 1 << 1); //通道1 被预选， 才可转换通道1 

    ADC->CR = ADC->CR | ( 1 << 0); //使能adc ，  

}

unsigned short get_value(unsigned char channel){

	ADC->PCSEL = ADC->PCSEL | (1 << channel); //通道被预选
    ADC->SQR1 = ADC->SQR1 & ~(0x1f << 6); 
    ADC->SQR1 = ADC->SQR1 | (channel << 6);//转换的第一个通道是通道ch
    ADC->CR = ADC->CR | ( 1 << 2); // bit2 = 1， 开启adc转换， *************读adc 值时候， 才会开启	
    
    while(!(ADC->ISR & ( 1 << 2))) ; 
    return ADC->DR & 0xffff;
	
}