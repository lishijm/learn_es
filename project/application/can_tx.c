#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int main(){
    int can_fd,nbytes;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame[2]={{0}};
    can_fd=socket(PF_CAN,SOCK_RAW,CAN_RAW);
    strcpy(ifr.ifr_name,"can0");
    ioctl(can_fd,SIOCGIFINDEX,&ifr);
    addr.can_family=AF_CAN;
    addr.can_ifindex=ifr.ifr_ifindex;
    bind(can_fd,(struct sockaddr *)&addr,sizeof(addr));
    u_int8_t send_data1[8]={(u_int8_t)0x01,(u_int8_t)0x02,(u_int8_t)0x03,(u_int8_t)0x04,(u_int8_t)0x05,(u_int8_t)0x06,(u_int8_t)0x07,(u_int8_t)0x08};
    u_int8_t send_data2[8]={(u_int8_t)0x08,(u_int8_t)0x07,(u_int8_t)0x06,(u_int8_t)0x05,(u_int8_t)0x04,(u_int8_t)0x03,(u_int8_t)0x02,(u_int8_t)0x01};

    setsockopt(can_fd,SOL_CAN_RAW,CAN_RAW_FILTER,NULL,0);
    frame[0].can_id=CAN_EFF_FLAG|0x1314;
    frame[0].can_dlc=8;
    strcpy(frame[0].data,send_data1);
    frame[1].can_id=CAN_EFF_FLAG|0x1314;
    frame[1].can_dlc=8;
    strcpy(frame[1].data,send_data2);

    while (1)
    {
        nbytes=write(can_fd,&frame[0],sizeof(frame[0]));
        printf("%d,%ld",nbytes,sizeof(frame[0]));
        if(nbytes!=sizeof(frame[0])){
            printf("send error frame[0]\r\n");
            break;
        }
        sleep(1);
        nbytes=write(can_fd,&frame[1],sizeof(frame[1]));
        if(nbytes!=sizeof(frame[1])){
            printf("send error frame[1]\r\n");
            break;
        }
        sleep(1);
    }
    close(can_fd);
    return 0;
}