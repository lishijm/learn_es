#include "sdio_sdcard.h"

HAL_SD_CardInfoTypeDef hsd_info;

void sdcard_info(void){
    HAL_SD_CardCIDTypeDef sdcard_cid;
    HAL_SD_GetCardCID(&hsd,&sdcard_cid);
    HAL_SD_GetCardInfo(&hsd,&hsd_info);
    switch (hsd_info.CardType)
    {
        case CARD_SDSC:
            if(hsd_info.CardVersion==CARD_V1_X){
                printf("Card Type:SDSC V1\r\n");
            }
            else if(hsd_info.CardVersion==CARD_V2_X){
                printf("Card Type:SDSC V2\r\n");
            }
            break;
        case CARD_SDHC_SDXC:
            printf("Card Type:SDHC V2\r\n");
            break;
        default:
            break;
    }
    printf("Card ManufacturerID:%d\r\n",sdcard_cid.ManufacturerID);
    printf("Card ManufacturerDate:%d\r\n",sdcard_cid.ManufactDate);
    printf("Card RCA:%d\r\n",(uint32_t)hsd_info.RelCardAdd);
    printf("LogBlockNbr:%d\r\n",(uint32_t)hsd_info.LogBlockNbr);
    printf("LogBlockSize:%d\r\n",(uint32_t)hsd_info.LogBlockSize);
    printf("BlockNBR:%d\r\n",(uint32_t)hsd_info.BlockNbr);
    printf("BlockSize:%d\r\n",(uint32_t)hsd_info.BlockSize);
    printf("CardCapacity:%dMB\r\n",(uint32_t)SD_TOTAL_SIZE_MB(&hsd));
}

uint8_t sdcard_read(uint8_t *pbuf,uint32_t saddr,uint32_t cnt){
    uint8_t sta=HAL_OK;
    uint32_t timeout=SD_TIMEOUT;
    uint32_t lesector=saddr;
    __disable_irq();
    sta=HAL_SD_ReadBlocks(&hsd,(uint8_t *)pbuf,lesector,cnt,SD_TIMEOUT);

    while (((HAL_SD_GetCardState(&hsd)==HAL_SD_CARD_TRANSFER)?SD_TRANSFER_OK:SD_TRANSFER_BUSY)!=SD_TRANSFER_OK){
        if(timeout--==0){
            sta=SD_TRANSFER_BUSY;
        }
    }
    __enable_irq();
    return sta;
}

uint8_t sdcard_write(uint8_t *pbuf,uint32_t saddr,uint32_t cnt){
    uint8_t sta=HAL_OK;
    uint32_t timeout=SD_TIMEOUT;
    uint32_t lesector=saddr;
    __disable_irq();
    sta=HAL_SD_WriteBlocks(&hsd,(uint8_t *)pbuf,lesector,cnt,SD_TIMEOUT);
    while (((HAL_SD_GetCardState(&hsd)==HAL_SD_CARD_TRANSFER)?SD_TRANSFER_OK:SD_TRANSFER_BUSY)!=SD_TRANSFER_OK){
        if(timeout--==0){
            sta=SD_TRANSFER_BUSY;
        }
    }
    __enable_irq();
    return sta;
}

void sd_write_test(uint32_t secaddr,uint32_t seccnt){
    uint16_t i;
    uint8_t *buf;
    uint8_t sta=0;
    uint8_t bufarr[512];
    for(i=0;i<512;i++){
        bufarr[i]=i;
    }
    buf=bufarr;
    sta=sdcard_write(buf,secaddr,seccnt);
    if(sta==0){
        printf("WRITE\r\n");
        printf("SECTOR %d DATA:\r\n", secaddr);
        for (i = 0; i <512; i++){
            printf("%x ", buf[i]);
        }
        printf("\r\nDATA ENDED\r\n");
    }
    else{
        printf("err:%d\r\n", sta);
    }
    return ;
}

void sd_read_test(uint32_t secaddr,uint32_t seccnt){
    uint16_t i;
    uint8_t *buf;
    uint8_t sta=0;
    uint8_t bufarr[512];
    buf=bufarr;
    sta=sdcard_read(buf,secaddr,seccnt);
    if(sta==0){
        printf("READ\r\n");
        printf("SECTOR %d DATA:\r\n", secaddr);
        for (i = 0; i <512; i++){
            printf("%x ", buf[i]);  /* 打印secaddr开始的扇区数据 */
        }
        printf("\r\nDATA ENDED\r\n");
    }
    else{
        printf("err:%d\r\n", sta);
    }
}