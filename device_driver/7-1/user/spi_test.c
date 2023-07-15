#include <stdint.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <getopt.h> 
#include <fcntl.h> 
#include <sys/ioctl.h> 
#include <linux/types.h> 
#include <linux/spi/spidev.h> 
 
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0])) 
 
static void pabort(const char *s) 
{ 
    perror(s); 
    abort(); 
} 
 
static const char *device = "/dev/spidev0.0"; 
static uint8_t mode; 
static uint8_t bits = 8; 
static uint32_t speed = 400000; 
static uint16_t delay = 0; 
 
int main(int argc, char *argv[]) 
{ 
    int ret = 0; 
    int fd; 
 
	if (argc != 2) {
		printf("usage: %s <device-file>\n", argv[0]);
		return 1;
	}

    fd = open(device, O_RDWR);  //打开设备文件 
    if (fd < 0) 
        pabort("can't open device"); 
 
    /*
     * spi mode //设置spi设备模式
     */ 
    ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);    //写模式 
    if (ret == -1) 
        pabort("can't set spi mode"); 
 
    /*
     * bits per word    //设置每个字含多少位
     */ 
    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);   //写每个字含多少位 
    if (ret == -1) 
        pabort("can't set bits per word"); 
 
    /*
     * max speed hz     //设置速率
     */ 
    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);   //写速率 
    if (ret == -1) 
        pabort("can't set max speed hz"); 
 
    //打印模式,每字多少位和速率信息 
    printf("spi mode: %d\n", mode); 
    printf("bits per word: %d\n", bits); 
    printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000); 
 
    //transfer(fd);   //传输测试 
	int i = 0;
	unsigned char num[20] = {0x00,0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
	int pos = 0;
	unsigned char buf[2];

	while(1) {
		pos = 1 << (i % 4);
		buf[0] = pos;
		buf[1] = num[0];
		if (write(fd, buf, 2) < 0)
			perror("write");
		i++;
		if (i == 4) {
			i = 0;
		}
		usleep(3000);
	}
 
    return ret; 
} 
