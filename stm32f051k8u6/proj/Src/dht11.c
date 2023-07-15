#include "dht11.h"
#include "gpio.h"
#include "tim.h"
#include "stdio.h"
#include "iot.h"

void us_delay(uint32_t dtime){
  LL_TIM_SetCounter(TIM6,0);
  while(LL_TIM_GetCounter(TIM6)<dtime){

  }
}

int inflevel(int level,int timeout){
    int count=0;
    while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8)==level){
        us_delay(1);
        count++;
        if(count>timeout){
            puts("time out");
            break;
        }
    }
    return count;
}

void dhtinf(){
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure GPIO pin : PB8 */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_Delay(18);

    /*Configure GPIO pin : PB8 */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    us_delay(30);

    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8)==GPIO_PIN_SET){
        puts("senseor no re");
        return;
    }
    inflevel(0,80);
    inflevel(1,80);

    uint8_t inf[5];
    int i,j,low_level,high_level;

    for(i=0;i<5;i++){
        uint8_t byte=0;
        for(j=0;j<8;j++){
            low_level=inflevel(0,100);
            high_level=inflevel(1,100);
            if(low_level>high_level){
                byte=byte&(~(0x80>>j));
            }
            else{
                byte=byte|(0x80>>j);
            }
        }
        inf[i]=byte;
    }
    inflevel(0,100);

    uint8_t checksum=inf[0]+inf[1]+inf[2]+inf[3];

    if(checksum!=inf[4]){
        puts("rinf err");
        return;
    }

    char dht11_information[32];
    sprintf(dht11_information,"humidity:%d.%d;tempture:%d.%d",inf[0],inf[1],inf[2],inf[3]);
    printf("%s\n",dht11_information);
    send_message(dht11_information);
}
