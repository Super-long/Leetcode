// 打印奇偶 这里调整成ABC 使用信号量
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<semaphore.h>

#define PTH_NUMS 3

typedef struct pthread_arg
{
    pthread_t tid;
    int pthno;
    int fd;

}ptharg;

sem_t sem[3];
void *pth_fun(void *pth_arg)
{
    int flag = ((ptharg *)pth_arg) -> pthno;
    int i = -1;
    while(1)
    {
        if(flag == 0)
        {
            sem_wait(&sem[0]);
            fprintf(stderr,"A");
            sleep(1);
            sem_post(&sem[1]);
        }
        else if(flag == 1)
        {
            sem_wait(&sem[1]);
            fprintf(stderr,"B");
            sleep(1);
            sem_post(&sem[2]);
        }
        else if(flag == 2)
        {
            sem_wait(&sem[2]);
            fprintf(stderr,"C");
            sleep(1);
            sem_post(&sem[0]);
        }
    }
    return NULL;
}

void signal_fun(int signo)
{
    for(int i = 0; i< 3;i++)
    {
        sem_destroy(&sem[i]);
    }
    exit(0);
}
int main(void)
{
    signal(SIGINT,signal_fun);
    sem_init(&sem[0],0,1);
    sem_init(&sem[1],0,0);
    sem_init(&sem[2],0,0);
    ptharg pth_arg[PTH_NUMS];
    int i = 0;
    int ret = 0;
    for(i = 0; i< PTH_NUMS;i++)
    {
        pth_arg[i].pthno = i;
        ret = pthread_create(&pth_arg[i].tid,NULL,pth_fun,(void *)&pth_arg[i]);
        if(ret != 0)
            printf("pthread_create failed");
    }
    while(1);
}