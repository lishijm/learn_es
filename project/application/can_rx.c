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
    int can_fd,nbtyes,ret;
    char resavedata[8];
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;
    struct can_filter rfilter;
    can_fd=socket(PF_CAN,SOCK_RAW,CAN_RAW);
    strcpy(ifr.ifr_name,"can0");
    ioctl(can_fd,SIOCGIFINDEX,&ifr);
    addr.can_family=AF_CAN;
    addr.can_ifindex=ifr.ifr_ifindex;
    ret=bind(can_fd,(struct sockaddr *)&addr,sizeof(addr));
    printf("bind ret=%d\r\n",ret);
    rfilter.can_id=0x12;
    rfilter.can_mask=CAN_SFF_MASK;

    ret=setsockopt(can_fd,SOL_CAN_RAW,CAN_RAW_FILTER,&rfilter,sizeof(rfilter));
    printf("setsockopt ret=%d,before while\r\n",ret);
    while (1)
    {
        nbtyes=read(can_fd,&frame,sizeof(frame));
        if(nbtyes>0){
            strcpy(resavedata,(u_int8_t *)frame.data);
            printf("ID=0x%x DLC=%d resavedata=%s\r\n",frame.can_id,frame.can_dlc,resavedata);
            memset(resavedata,0,8);
        }
    }

    close(can_fd);
    return 0;

}