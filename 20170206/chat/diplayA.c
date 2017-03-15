 ///
 /// @file    diplayA.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-08 09:18:06
 ///
 
#include "func.h"
#define N 20
int main()
{
	//互斥访问信号量
	//建立/连接信号量
	int semid=semget(12,2,IPC_CREAT|0600);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	int ret;
	//设置信号量
	ret=semctl(semid,1,SETVAL,0);//在共享内存里写入pid以后置1
	if(-1==ret)
	{
		perror("perror");
		return -1;
	}
	//设置信号量的操作
	struct sembuf sp,sv,sp1;
	memset(&sp,0,sizeof(sp));
	memset(&sv,0,sizeof(sv));
	memset(&sp1,0,sizeof(sp1));
	sp.sem_num=0;
	sp.sem_op=-1;
	sp.sem_flg=SEM_UNDO;
	sv.sem_num=0;
	sv.sem_op=1;
	sv.sem_flg=SEM_UNDO;
	sp1.sem_num=1;
	sp1.sem_op=-1;
	sp1.sem_flg=SEM_UNDO;

	//接收数据的字符串
	char buf[N]={};
	//共享内存
	//开辟共享内存
	int shmid=shmget(12,sizeof(char)*N,IPC_CREAT|0600);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	char* p;
	//共享内存映射
	p=(char*)shmat(shmid,NULL,0);
	if((char*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	memset(p,0,sizeof(char)*N);
	
	//发送自己的pid
	int pid=getpid();
	sprintf(buf,"%d",pid);
	memcpy(p,buf,sizeof(char)*N);
	semop(semid,&sv,1);
	
	semop(semid,&sp1,1);//等待chatA还行

	while(1)
	{
		semop(semid,&sp,1);
		memcpy(buf,p,sizeof(char)*N);
		memset(p,0,sizeof(char)*N);
		puts(buf);
	}
}
