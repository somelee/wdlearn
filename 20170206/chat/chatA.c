 ///
 /// @file    chatA.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-07 13:22:28
 ///
 
//通讯A端
#include "func.h"

//接收字符串的长度
#define N 20

struct Del
{
	int pidme;
	int piddisplay;
	int pidit;
	int shmid;
	int semid;
	int fdr;
};
struct Del *pdel;

void sig(int signum)
{
	kill(pdel->pidit,SIGINT);//给对端发送关闭信号
	kill(pdel->piddisplay,SIGINT);//给显示端发送关闭信号
	close(pdel->fdr);//关闭读端
	shmctl(pdel->shmid,IPC_RMID,0);//删除共享内存
	semctl(pdel->semid,0,IPC_RMID,1);     //删除信号量
	exit(0);//退出程序
}

int main(int argc,char* argv[])
{
	//检查传入的通道数是否正确，
	//下次可修改为运行程序时创建通道，结束时删除通道
	if(3!=argc)    
	{
		printf("Pipe error\n");
		return -1;
	}

	//定义SIGINT函数传入数据
	struct Del delete;
	pdel=&delete;
	//设置退出信号函数
	signal(SIGINT,sig);

	printf("signal over\n");

	//打开通道2的读端
	int fdr=open(argv[2],O_RDONLY);
	if(-1==fdr)
	{
		perror(argv[2]);
		return -1;
	}
	//打开通道1的写端
	int fdw=open(argv[1],O_WRONLY);
	if(-1==fdw)
	{
		perror(argv[1]);
		return -1;
	}
	
	pdel->fdr=fdr;
	
	printf("pipo over\n");

	//互斥访问信号量
	//建立信号量
	int semid=semget(12,2,IPC_CREAT|0600);
	//建立两个信号量
	if(-1==pdel->semid)
	{
		perror("semget");
		return -1;
	}
	pdel->semid=semid;
	//初始化信号量
	int ret;
	ret=semctl(semid,0,SETVAL,0);
	//初始化信号0为0
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	ret=semctl(semid,1,SETVAL,0);
	//初始化信号1为0
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	//设置信号量的操作
	struct sembuf sp,sv,sv1;
	memset(&sp,0,sizeof(sp));
	memset(&sv,0,sizeof(sv));
	memset(&sv1,0,sizeof(sv1));
	sp.sem_num=0;
	sp.sem_op=-1;
	sp.sem_flg=SEM_UNDO;
	sv.sem_num=0;
	sv.sem_op=1;
	sv.sem_flg=SEM_UNDO;
	sv1.sem_num=1;
	sv1.sem_op=1;
	sv1.sem_flg=SEM_UNDO;

	printf("sem over\n");

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
	pdel->shmid=shmid;
	char* p;
	//共享内存地址映射
	p=(char*)shmat(shmid,NULL,0);
	if((char*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	memset(p,0,sizeof(char)*N);

	printf("sh over\n");

	//从管道发送自己pid和等待接收对端pid
	pdel->pidme=getpid();
	write(fdw,&pdel->pidme,sizeof(int));
	read(fdr,&pdel->pidit,sizeof(int));
	
	printf("pidme=%d,pidit=%d\n",pdel->pidme,pdel->pidit);

	//等待显示端发送pid
	semop(semid,&sp,1);
	memcpy(buf,p,sizeof(char)*N);
	memset(p,0,sizeof(char)*N);
	
	pdel->piddisplay=atoi(buf);

	printf("piddisplay=%d\n",pdel->piddisplay);
	
	//初始化完成
	printf("chatA started successfully\n");
	fd_set rdset;

	semop(semid,&sv1,1);//显示程序运行

	//循环等待终端输入和管道发送的数据
	while(1)
	{
		//等待函数设置
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		//管道发来数据或者终端收到数据
		if(ret>0)
		{
			//管道收到数据
			if(FD_ISSET(fdr,&rdset))
			{
				memset(buf,0,sizeof(char)*N);
				if(read(fdr,buf,sizeof(char)*(N-1))>0)
				{
					//生产者，向共享内存写入数据
					strcpy(p,buf);
					semop(semid,&sv,1);
				}else{
					break;
				}
			}
			//终端输入数据
			if(FD_ISSET(STDIN_FILENO,&rdset))
			{
				memset(buf,0,sizeof(char)*N);
				if(read(STDIN_FILENO,buf,sizeof(char)*(N-1)))
				{
					write(fdw,buf,strlen(buf)-1);
				}else{
					break;
				}
			}
		}
	}
	return 0;
}
 
