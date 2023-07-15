#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<time.h>

int main()
{
    struct timeval time_now = {0};
    long time_sec = 0;//秒
    long time_mil = 0;//1毫秒 = 1秒/1000 
    long time_mic = 0;//1微秒 = 1毫秒/1000

    gettimeofday(&time_now,NULL);
    time_sec = time_now.tv_sec;
    time_mil = time_sec * 1000 + time_now.tv_usec/1000;
    time_mic = time_now.tv_sec*1000*1000 + time_now.tv_usec;

    printf("second %ld\n",time_sec);
    printf("millisecond %ld\n",time_mil);
    printf("microsecond %ld\n",time_mic);

    char filn[17]={0};
    sprintf(filn,"%ld.dat",time_mil);
    FILE *fp=NULL;

    fp=fopen(filn,"w");

    __pid_t pid=-1;
    pid=fork();
    if(0==pid){
        printf("x\n");
        char input;
        scanf("%c",&input);
        if(input=='b'){
            kill(getppid(),SIGUSR1);
            kill(getpid(),SIGUSR1);
        }
    }

    while(1){
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                fprintf(fp,"%d",j);
            }
            fprintf(fp,"\n");
        }
        sleep(3);
    }

    fclose(fp);

    return 0;
}