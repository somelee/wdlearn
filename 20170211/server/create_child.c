 ///
 /// @file    creat_child.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 09:58:23
 ///
 
#include "func.h"

//子进程处理函数
int child_main(int fdr)
{
	//初始化子进程
	int new_fd;
	short flag=1;
	//响应请求
	while(1)
	{
		recv_fd(fdr,&new_fd);//等待父进程分配任务，接收发送数据的文件描述符
		printf("connect success\n");
		handle_request(new_fd);	//向new_fd发送数据实现传输功能
		write(fdr,&flag,sizeof(flag));//告诉父进程任务完成
	}
	return 0;
}
//创建子进程
int create_child(int count,pcdata p)
{
	int i;
	int fds[2];
	pid_t pid;
	for(i=0;i<count;i++)//创建子进程
	{
		socketpair(AF_LOCAL,SOCK_STREAM,0,fds);//生成子进程对应的通信管道
		pid=fork();
		if(!pid)
		{
			close(fds[1]);
			child_main(fds[0]);//子进程请求函数，使用管道fds[0]给子进程分配任务并通讯
		}
		close(fds[0]);
		//登记子进程
		p[i].pid=pid;
		p[i].fdw=fds[1];
		p[i].busy=0;
	}
	return 0;
}
