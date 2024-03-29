#include<unistd.h>
#include<sys/mman.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
 
struct mt
{
    int num;
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;
};
 
 
int main(void)
{
    
    int i;
    struct mt* mm;
 
    pid_t pid;
    
    pthread_mutexattr_init(&mm->mutexattr);         // 初始化 mutex 属性
    pthread_mutexattr_setpshared(&mm->mutexattr, PTHREAD_PROCESS_SHARED);               // 修改属性为进程间共享
 
    pthread_mutex_init(&mm->mutex,&mm->mutexattr);      // 初始化一把 mutex 锁
    
    pid = fork();
    if( pid == 0 )          // 子进程
    {
        for( i=0; i<10;i++ )
        {
            pthread_mutex_lock(&mm->mutex);
            (mm->num)++;
            printf("-child--------------num++    %d\n",mm->num);
            pthread_mutex_unlock(&mm->mutex);
            sleep(1);
        }
    
    }
    else 
    {
        for( i=0;i<10;i++)
        {
            sleep(1); 
            pthread_mutex_lock(&mm->mutex);
            mm->num += 2;
            printf("--------parent------num+=2   %d\n",mm->num);
            pthread_mutex_unlock(&mm->mutex);
        
        }
        wait(NULL);
 
    }
    pthread_mutexattr_destroy(&mm->mutexattr);  // 销毁 mutex 属性对象
    pthread_mutex_destroy(&mm->mutex);          // 销毁 mutex 锁
 
    return 0;
}