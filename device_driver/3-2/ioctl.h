#ifndef _IOCTL_H_
#define _IOCTL_H_



#define IOCTL_CMD_LED1_ON _IO('e', 1)
#define IOCTL_CMD_LED1_OFF _IO('e', 2)


#define IOCTL_SET_SIZE _IOW('e', 3, int)
#define IOCTL_GET_SIZE _IOR('e', 4, int)

#define IOCTL_SET_INT_ARRAY _IOW('e', 5, int [5])


#define GET_ARGS_SIZE(cmd) (cmd >> 16 & 0x3fff)
#endif
