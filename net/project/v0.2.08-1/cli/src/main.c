#include "../include/cli.h"

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
    while(flag){
        scanf("%d",&sel);
        switch(sel){
            case 1:
                send(sockFd,PUSH,strlen(PUSH)+1,0);
                push_inf(sockFd);
                break;
            case 2:
                send(sockFd,SEARCH,strlen(SEARCH)+1,0);
                search_inf(sockFd);
                break;
            case 3:
                send(sockFd,LOOK,strlen(LOOK)+1,0);
                look_inf(sockFd);
                break;
            case 4:
                send(sockFd,UPDATE,strlen(UPDATE)+1,0);
                update_inf(sockFd);
                break;
            case 5:
                send(sockFd,DEL,strlen(DEL)+1,0);
                del_inf(sockFd);
                break;
            default:
                send(sockFd,QUIT,strlen(QUIT)+1,0);
                flag=0;
                break;
        }
    }
    //关闭套接字
    close(sockFd);

    return 0;
}