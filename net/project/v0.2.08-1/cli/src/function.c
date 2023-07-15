#include "../include/cli.h"

void push_inf(int sockFd)
{
    char name[20],inf[20],buf[BUFSIZ];
    int id,class,ret;
    
    printf("请输入学号：\n");
    scanf("%d",&id);
    memset(inf,0,sizeof(inf));
    sprintf(inf,"#%d#",id);
    send(sockFd,inf,strlen(inf),0);
    
    printf("请输入姓名：\n");
    scanf("%s",name);
    send(sockFd,name,strlen(name),0);
    
    printf("请输入班级：\n");
    scanf("%d",&class);
    memset(inf,0,sizeof(inf));
    sprintf(inf,"#%d#",class);
    send(sockFd,inf,strlen(inf),0);
    
    puts("send_inf ok");

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

void look_inf(int sockFd)
{
    int row=0,column=0,i,j;
    char head[128]={0},inf[128];
    recv(sockFd,head,sizeof(head),0);
    sscanf(head,"#%d#%d#",&row,&column);
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            memset(inf,0,sizeof(inf));
            recv(sockFd,inf,sizeof(inf),0);
            printf("%-10s",inf);
        }
        printf("\n");
    }
}

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

void update_inf(int sockFd)
{
    int id,sel,class;
    char name[20]={0},buf[20]={0},idbuf[20]={0};
    printf("输入你要修改的值所在ID号\n");
    scanf("%d",&id);
    sprintf(idbuf,"#%d#",id);
    send(sockFd,idbuf,sizeof(idbuf),0);
    printf("选择你要修改的类型\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            send(sockFd,NAME,strlen(NAME)+1,0);
            printf("输入新名字\n");
            scanf("%s",name);
            send(sockFd,name,sizeof(name),0);
            break;
        case 2:
            send(sockFd,CLASS,strlen(CLASS)+1,0);
            printf("请输入新班级号\n");
            scanf("%d",&class);
            sprintf(buf,"#%d#",class);
            send(sockFd,buf,sizeof(buf),0);
            break;
        default:
            break;
    }
}

void del_inf(int sockFd){
    int id;
    char idbuf[20]={0};
    printf("请输入需要删除的项的学号\n");
    scanf("%d",&id);
    sprintf(idbuf,"#%d#",id);
    send(sockFd,idbuf,sizeof(idbuf),0);
}
