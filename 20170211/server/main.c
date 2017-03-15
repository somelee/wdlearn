 ///
 /// @file    main.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 09:47:10
 ///
 
#include "func.h"

int main(int argc,char* argv[])
{
	if(4!=argc)
	{
		printf("argv error\n");
		return -1;
	}
	int count=atoi(argv[3]);
	pcdata p=(pcdata)calloc(count,sizeof(cdata));
	create_child(count,p);//创建子进程
	int sfd;
	net_init(&sfd,argv[1],argv[2]);//绑定ip和port
	listen(sfd,count);
	int epfd;
	epfd=epoll_create(1);
	struct epoll_event event,*evs;
	evs=(struct epoll_event*)calloc(count+1,sizeof(event));
	memset(&event,0,sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=sfd;
	int ret;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	int i;
	for(i=0;i<count;i++)
	{
		event.events=EPOLLIN;
		event.data.fd=p[i].fdw;
		epoll_ctl(epfd,EPOLL_CTL_ADD,p[i].fdw,&event);
	}
	printf("sever launch\n");
	int ret1,j,new_fd;
	short flag;
	while(1)
	{
		memset(evs,0,sizeof(event)*(count+1));
		ret1=epoll_wait(epfd,evs,count+1,-1);
		if(ret1>0)
		{
			for(i=0;i<ret1;i++)
			{
				if(evs[i].data.fd==sfd)//客户端连接，分配子进程
				{
					new_fd=accept(sfd,NULL,NULL);
					for(j=0;j<count;j++)
					{
						if(0==p[j].busy)
						{
							send_fd(p[j].fdw,new_fd);//发送文件描述符给子进程，并启动子进程
							p[j].busy=1;
							break;
						}
					}
					close(new_fd);
				}
				for(j=0;j<count;j++)
				{
					if(evs[i].data.fd==p[j].fdw)
					{
						read(p[j].fdw,&flag,sizeof(flag));
						p[j].busy=0;
						//子进程任务结束
					}
				}
			}
		}
	}
	wait(NULL);
	close(sfd);
	close(epfd);
	return 0;
}
