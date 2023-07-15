// 气体值>10不正常，接近1无0，湿度，温度，火焰无火0/1有火，风扇0无1转，灯光强度
// 继电器0关1开，蜂鸣器0不响1响，led0不亮1亮，三灯闪，火焰
// FF所有数据，F0继电器开，0F继电器关，70风扇开，07风扇关，30蜂鸣器开，03蜂鸣器关,A0灯亮，0A灯灭。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <linux/can/raw.h>

#define loop  0
#define aplic 1
#define debug 0

#if aplic
#define SERV_PORT 5050
#define SERV_IP "192.168.8.11"
#endif

#if aplic
int aplic_sock_init(void){
    int sockFd=socket(AF_INET,SOCK_STREAM,0);
    if(sockFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");
    
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=inet_addr(SERV_IP);
    int ret=connect(sockFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("connect error");
        exit(1);
    }
    printf("connect ok\n");

    return sockFd;

}
#endif

int main(){
    int nbtyes,ret,i;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame trframe,reframe;
    struct can_filter rfilter;

    int canFD=socket(PF_CAN,SOCK_RAW,CAN_RAW);
    
    strcpy(ifr.ifr_name,"can0");
    ioctl(canFD,SIOCGIFINDEX,&ifr);
    addr.can_family=AF_CAN;
    addr.can_ifindex=ifr.ifr_ifindex;
    
    ret=bind(canFD,(struct sockaddr *)&addr,sizeof(addr));
    printf("bind ret=%d\r\n",ret);
    
    rfilter.can_id=0x1314;
    rfilter.can_mask=CAN_EFF_MASK;

    ret=setsockopt(canFD,SOL_CAN_RAW,CAN_RAW_FILTER,&rfilter,sizeof(rfilter));
    printf("setsockopt ret=%d,before while\r\n",ret);

    trframe.can_id=CAN_EFF_FLAG|0x1314;
    trframe.can_dlc=8;
#if aplic
    int aplicFD=aplic_sock_init();
    char trbuf1[40];
    char trbuf2[40];
#endif

    unsigned char transbuf[8];
#if !loop
    unsigned char recbuf2[8];
#endif
#if !aplic
    u_int8_t send_data_inf[8]={(u_int8_t)0xFF,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00};
    u_int8_t send_data_relayon[8]={(u_int8_t)0xF0,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00};
    u_int8_t send_data_relayoff[8]={(u_int8_t)0x0F,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00};
    u_int8_t send_data_ledon[8]={(u_int8_t)0xA0,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00};
    u_int8_t send_data_ledoff[8]={(u_int8_t)0x0A,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00,(u_int8_t)0x00};
#endif

    while (1)
    {
#if aplic
        ret=recv(aplicFD,transbuf,1,0);
        if(ret<0){
            perror("recv error");
            continue;
        }
        memcpy(trframe.data,transbuf,8);
        memset(transbuf,8,0);
#endif
#if !aplic
        memcpy(trframe.data,send_data_inf,8);
#endif
        nbtyes=write(canFD,&trframe,sizeof(trframe));
        printf("send_inf:%d,%ld\r\n",nbtyes,sizeof(trframe));
#if loop
        for(i=0;i<8;i++){
            nbtyes=read(canFD,&reframe,sizeof(reframe));
            if(0x1314==reframe.can_id){
                strcpy(transbuf,reframe.data);
                send(aplicFD,transbuf,8,0);
            }
        }
#endif
#if !loop
        nbtyes=read(canFD,&reframe,sizeof(reframe));
        memcpy(transbuf,reframe.data,8);
#if debug
        printf("%d\r\n",nbtyes);
        if(nbtyes>0){
            printf("ID=0x%x DLC=%d 第%d数据：气体：%d，接近：%d，湿度：%d，温度：%d，火焰：%d，风扇：%d，光照：%d\r\n",reframe.can_id,reframe.can_dlc,
                reframe.data[0],reframe.data[1],reframe.data[2],reframe.data[3],reframe.data[4],reframe.data[5],reframe.data[6],reframe.data[7]);
        }
#endif
#if aplic
        sprintf(trbuf1,"*%d*%d*%d*%d*%d*%d*%d*%d*",transbuf[0],transbuf[1],transbuf[2],transbuf[3],transbuf[4],transbuf[5],transbuf[6],transbuf[7]);
#endif
        nbtyes=read(canFD,&reframe,sizeof(reframe));
        memcpy(recbuf2,reframe.data,8);
#if debug
        printf("%d\r\n",nbtyes);
        if(nbtyes>0){
            printf("ID=0x%x DLC=%d 第%d数据：继电器：%d，蜂鸣器：%d，led1：%d，led2：%d，火焰：%d\r\n",reframe.can_id,reframe.can_dlc,
                reframe.data[0],reframe.data[1],reframe.data[2],reframe.data[3],reframe.data[4],reframe.data[5]);
        }
#endif
#if aplic
        sprintf(trbuf2,"*%d*%d*%d*%d*%d*%d*%d*%d*",recbuf2[0],recbuf2[1],recbuf2[2],recbuf2[3],recbuf2[4],recbuf2[5],recbuf2[6],recbuf2[7]);
        send(aplicFD,trbuf1,sizeof(trbuf1),0);
        usleep(500);
        send(aplicFD,trbuf2,sizeof(trbuf2),0);
#endif
#if !aplic
        printf("%d %d %d %d %d %d %d %d\r\n",transbuf[0],transbuf[1],transbuf[2],transbuf[3],transbuf[4],transbuf[5],transbuf[6],transbuf[7]);
        printf("%d %d %d %d %d %d %d %d\r\n",recbuf2[0],recbuf2[1],recbuf2[2],recbuf2[3],recbuf2[4],recbuf2[5],recbuf2[6],recbuf2[7]);

#endif
#endif
    }

    close(canFD);
    return 0;
}