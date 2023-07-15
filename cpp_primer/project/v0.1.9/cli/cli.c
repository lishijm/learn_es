#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define SERV_PORT 5050
#define SIGNUP "signup"
#define LOGIN "login"
#define QUIT "quit"
#define AD_VIEW "a_view"
#define SEARCH "search"

#if 0
void img()
{
    int fd = open("/dev/video0",O_RDWR);
    if (fd < 0){
        perror("打开设备失败");
        exit(1);
    }

    //获取摄像头支持格式 ioctl(文件描述符,命令，与命令对应的结构体)
    struct v4l2_format vfmt;

    vfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE; //摄像头采集
    vfmt.fmt.pix.width = 1280; //设置摄像头采集参数，不可以任意设置
    vfmt.fmt.pix.height = 720;
    vfmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG; //设置为mjpg格式，则我可以直接写入文件保存，YUYV格式保存后需要转换格式才能查看
    
    int ret = ioctl(fd,VIDIOC_S_FMT,&vfmt);
    if (ret < 0){
        perror("设置格式失败1");
    }

    //申请内核空间
    struct v4l2_requestbuffers reqbuffer;
    reqbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    reqbuffer.count = 4; //申请4个缓冲区
    reqbuffer.memory = V4L2_MEMORY_MMAP;  //映射方式
    ret = ioctl(fd,VIDIOC_REQBUFS,&reqbuffer);
    if (ret < 0){
        perror("申请空间失败");
    }
   
    //映射
    unsigned char *mptr[4];//保存映射后用户空间的首地址
    unsigned int size[4];
    struct v4l2_buffer mapbuffer;
    //初始化type和index
    mapbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    for(int i = 0; i <4;i++) {
        mapbuffer.index = i;
        ret = ioctl(fd,VIDIOC_QUERYBUF,&mapbuffer); //从内核空间中查询一个空间作映射
        if (ret < 0){
            perror("查询内核空间失败");
        }
        //映射到用户空间
        mptr[i] = (unsigned char *)mmap(NULL,mapbuffer.length,PROT_READ|PROT_WRITE,MAP_SHARED,fd,mapbuffer.m.offset);
        size[i] = mapbuffer.length; //保存映射长度用于后期释放
        //查询后通知内核已经放回
        ret = ioctl(fd,VIDIOC_QBUF,&mapbuffer); 
        if (ret < 0){
            perror("放回失败");
        }
    }
    //开始采集
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret = ioctl(fd,VIDIOC_STREAMON,&type); 
    if (ret < 0){
        perror("开启失败");
    }
    //从队列中提取一帧数据
    struct v4l2_buffer readbuffer;
    readbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE; //每个结构体都需要设置type为这个参赛要记住
    ret = ioctl(fd,VIDIOC_DQBUF,&readbuffer); 
    if (ret < 0){
        perror("读取数据失败");
    }
    FILE *file=fopen("img.jpg", "w+");  //打开一个文件
    fwrite( mptr[readbuffer.index],readbuffer.length,1,file);//写入文件
    fclose(file);    //写入完成，关闭文件
    
    //通知内核使用完毕
    ret = ioctl(fd, VIDIOC_QBUF, &readbuffer);
    if(ret < 0){
        perror("放回队列失败");
    }
	//停止采集
    ret = ioctl(fd,VIDIOC_STREAMOFF,&type);
	//释放映射
    for(int i=0; i<4; i++)munmap(mptr[i], size[i]);

    close(fd); //关闭文件描述符
}
#endif

void signup(int sockFd)
{
    char buf[BUFSIZ]={0};
    printf("请输入姓名：\n");
    scanf("%s",buf);
    send(sockFd,buf,strlen(buf),0);
    
    memset(buf,0,sizeof(buf));
    printf("请输入密码：\n");
    scanf("%s",buf);
    send(sockFd,buf,strlen(buf),0);
    
    memset(buf,0,sizeof(buf));
    printf("请再次输入密码：\n");
    scanf("%s",buf);
    send(sockFd,buf,strlen(buf),0);

    int flag;
    while(1){
        flag=0;
        memset(buf,0,sizeof(buf));
        recv(sockFd,buf,sizeof(buf),0);
        sscanf(buf,"#%d#",&flag);
        if(flag==0){
            puts("再次输入密码");
            memset(buf,0,sizeof(buf));
            printf("请输入密码：\n");
            scanf("%s",buf);
            send(sockFd,buf,strlen(buf),0);
            
            memset(buf,0,sizeof(buf));
            printf("请再次输入密码：\n");
            scanf("%s",buf);
            send(sockFd,buf,strlen(buf),0);
        }
        else{
            puts("密码无误");
            break;
        }
    }

    memset(buf,0,sizeof(buf));
    printf("请输入状态：\n");
    scanf("%s",buf);
    send(sockFd,buf,strlen(buf),0);

    flag=0;
    memset(buf,0,sizeof(buf));
    recv(sockFd,buf,sizeof(buf),0);
    sscanf(buf,"#%d#",&flag);
    if(flag==1){
        puts("注册成功");
    }
    else if(flag==0){
        puts("注册失败");
    }
#if 0
    else if(flag==0){

        img();
        puts("img ok");

        struct stat statbuf;
        stat("img.jpg",&statbuf);
        printf("%ld\n",statbuf.st_size);
        memset(inf,0,sizeof(inf));
        sprintf(inf,"#%ld#",statbuf.st_size);
        usleep(100000);
        send(sockFd,inf,sizeof(inf),0);
        usleep(100000);

        int fileFd;
        fileFd=open("img.jpg",O_RDONLY,0644);
        while(1){
            memset(buf,0,sizeof(buf));
            ret=read(fileFd,buf,sizeof(buf));
            if(ret==0){
                break;
            }
            else{
                send(sockFd,buf,ret,0);
            }
        }
        close(fileFd);
        remove("img.jpg");
    }
#endif
    return ;
}
#if 0
void search_inf(int sockFd)
{
    int id,num,i,flag;
    char sinf[10]={0},buf[12]={0},inf[128],flagbuf[5]={0};
    printf("请选择需要查询的学号\n");
    scanf("%d",&id);
    sprintf(sinf,"#%d#",id);
    send(sockFd,sinf,sizeof(sinf),0);
    
    recv(sockFd,flagbuf,sizeof(flagbuf),0);
    sscanf(flagbuf,"#%d#",&flag);
    if(0==flag){
        printf("没有此学生\n");
        return ;
    }
    else if(1==flag){
        recv(sockFd,buf,sizeof(buf),0);
        sscanf(buf,"#%d#",&num);
        printf("%d\n",num);
        for(i=0;i<num;i++){
            memset(inf,0,sizeof(inf));
            recv(sockFd,inf,sizeof(inf),0);
            printf("%-10s",inf);
        }
        printf("\n");
        char filename[20];
        memset(filename,0,sizeof(filename));
        sprintf(filename,"%d.jpg",id);

        int count=0;
        long legnth;
        char sizebuf[BUFSIZ],filebuf[BUFSIZ];
        memset(sizebuf,0,sizeof(sizebuf));
        recv(sockFd,sizebuf,sizeof(sizebuf),0);
        sscanf(sizebuf,"#%ld#",&legnth);

        if(legnth==0){
            return ;
        }
        int ret,fileFd;
        fileFd=open(filename,O_WRONLY|O_CREAT,0664);
        while(1){
            memset(buf,0,sizeof(buf));
            ret=recv(sockFd,buf,sizeof(buf),0);
            if(ret<0){
                perror("recv error");
                continue;
            }
            if(ret==0){
                break;
            }
            write(fileFd,buf,ret);
            count+=ret;
            if(count>=legnth){
                break;
            }
        }
        close(fileFd);

        getchar();
        getchar();
        remove(filename);
    }

}

void del_inf(int sockFd){
    int id,flag;
    char idbuf[20]={0};
    printf("请输入需要删除的项的学号\n");
    scanf("%d",&id);
    sprintf(idbuf,"#%d#",id);
    send(sockFd,idbuf,sizeof(idbuf),0);
    char flags[5];
    memset(flags,0,sizeof(flags));
    recv(sockFd,flags,sizeof(flags),0);
    sscanf(flags,"#%d#",&flag);
    if(flag==0){
        puts("没有此学生，删除无效");
        return ;
    }
    else if(flag==1){
        puts("删除成功");
        return ;
    }
}
#endif

void view_table(int sockFd)
{
    int row=0,column=0,i,j;
    char head[128]={0},inf[128];
    recv(sockFd,head,sizeof(head),0);
    sscanf(head,"#%d#%d#",&row,&column);
    printf("%d %d\n",row,column);
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            memset(inf,0,sizeof(inf));
            recv(sockFd,inf,sizeof(inf),0);
            printf("%-10s",inf);
        }
        printf("\n");
    }
    return ;
}

void search(int sockFd){
    char buf[BUFSIZ];
    puts("请输入查询姓名");
    memset(buf,0,sizeof(buf));
    scanf("%s",buf);
    send(sockFd,buf,sizeof(buf),0);

    int flag=0;
    memset(buf,0,sizeof(buf));
    recv(sockFd,buf,sizeof(buf),0);
    sscanf(buf,"#%d#",&flag);
    
    printf("%d\n",flag);

    if(flag==1){
        int row=0,column=0,i,j;
        char head[128]={0},inf[128];
        recv(sockFd,head,sizeof(head),0);
        sscanf(head,"#%d#%d#",&row,&column);
        printf("%d %d\n",row,column);
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                memset(inf,0,sizeof(inf));
                recv(sockFd,inf,sizeof(inf),0);
                printf("%-10s",inf);
            }
            printf("\n");
        }
    }
    else{
        puts("没有此用户");
    }

    return ;
    
}

void login(int sockFd){
    char buf[BUFSIZ]={0};
    printf("请输入姓名：\n");
    scanf("%s",buf);
    send(sockFd,buf,strlen(buf),0);
    
    memset(buf,0,sizeof(buf));
    printf("请输入密码：\n");
    scanf("%s",buf);
    send(sockFd,buf,strlen(buf),0);

    int log_flag=0;
    memset(buf,0,BUFSIZ);
    recv(sockFd,buf,sizeof(buf),0);
    sscanf(buf,"#%d#",&log_flag);

    int sel;
    if(log_flag==1){
        puts("login ok");
        int menu_flag=1;
        while(menu_flag){
            scanf("%d",&sel);
            switch (sel){
            case 1:
                send(sockFd,AD_VIEW,strlen(AD_VIEW)+1,0);
                view_table(sockFd);
                break;
            case 2:
                send(sockFd,SEARCH,strlen(SEARCH)+1,0);
                search(sockFd);
                break;
            default:
                menu_flag=0;
                break;
            }
        }
    }
    else{
        puts("login false");
    }
    puts("ad_log exit");
}

int main()
{
    //建立套接字
    int sockFd=socket(AF_INET,SOCK_STREAM,0);
    if(sockFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");
    //连接套接字
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=htons(INADDR_ANY);
    int ret=connect(sockFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("connect error");
        exit(1);
    }
    printf("connect ok\n");
    
    //选择
    int flag=1,sel;
    char selbuf[10]={0};
    scanf("%d",&sel);
    switch(sel){
        case 1:
            while(flag){
                scanf("%d",&sel);
                switch(sel){
                    case 1:
                        send(sockFd,SIGNUP,strlen(SIGNUP)+1,0);
                        signup(sockFd);
                        break;
                    case 2:
                        send(sockFd,LOGIN,strlen(LOGIN)+1,0);
                        login(sockFd);
                        break;
                    default:
                        send(sockFd,QUIT,strlen(QUIT)+1,0);
                        flag=0;
                        break;
                }
            }
            break;
        case 2:
            while(flag){
                scanf("%d",&sel);
                switch(sel){
                    case 1:
                        send(sockFd,LOGIN,strlen(LOGIN)+1,0);
                        login(sockFd);
                        break;
                    default:
                        send(sockFd,QUIT,strlen(QUIT)+1,0);
                        flag=0;
                        break;
                }
            }
        default:
            break;
    }
    //关闭套接字
    close(sockFd);

    return 0;
}