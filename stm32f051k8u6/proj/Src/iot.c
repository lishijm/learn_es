#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "iot.h"

uint32_t i,j;

const char *cmd[7]={
    "AT+CFUN=1\r\n",
    "AT+NSOCR=STREAM,6,6555,1\r\n",
    "AT+NSOCO=2,119.91.109.180,8344\r\n",
    "AT+NSOSD=2,56,636d643d31267569643d306339333835623935623631343962353865363036653661626336373563326126746f7069633d33323035310d0a\r\n",
    "AT+NSOSD=2,6,70696e670d0a\r\n",
    "AT+NSOSD=2",
    "636d643d32267569643d306339333835623935623631343962353865363036653661626336373563326126746f7069633d3332303531266d73673d"
};

void NBIOT_Init(void){
    for(i=0;i<4;i++){
        HAL_UART_Transmit(&huart2,(uint8_t *)cmd[i],strlen(cmd[i]),HAL_MAX_DELAY);
        for(j=0;j<strlen(cmd[i]);j++){
            USART2->TDR=*(cmd[i]+j);
            printf("%c",*(cmd[i]+j));
        }
        HAL_Delay(5000);
    }
}

void send_message(char *inf){
    for(i=0;i<strlen(cmd[3]);i++){
        USART2->TDR=*(cmd[3]+i);
        printf("%c",*(cmd[3]+i));
    }
    HAL_Delay(2000);
    char tmp_inf[256];
    for(i=0;i<strlen(inf);i++){
        sprintf(tmp_inf+i*2,"%0x",inf[i]);
    }
    char tmp_message[256];
    sprintf(tmp_message,"%s%s",cmd[6],tmp_inf);
    char message[256];
    sprintf(message,"%s,%d,%s0d0a\r\n",cmd[5],(strlen(tmp_message)+4)/2,tmp_message);
    for(i=0;i<strlen(message);i++){
        USART2->TDR=*(message+i);
        printf("%c",*(message+i));
    }
}
