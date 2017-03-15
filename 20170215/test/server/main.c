#include "head.h" 
#include "data.h"
#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("argc error.\n");
		return -1;
	}

	char conf[2][50]={};
	int ret;
	//读取配置文件
	ret=read_config(argv[1],conf);
	if(-1==ret)
	{
		printf("config error\n");
		return -1;
	}

	//创建子进程
	pcd cdata=(pcd)calloc(child_count,sizeof(cd));
	create_child(cdata);

	//初始化网络
	int sfd;
	net_init(&sfd,conf);
	listen(sfd,child_count);

	//加入检测
	int epfd;
	epfd=epoll_create(1);
	struct epoll_event event,*evs;
	evs=(struct epoll_event*)calloc(child_count+1,sizeof(event));
	memset(&event,0,sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=sfd;

	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	int i;
	for(i=0;i<child_count;i++)
	{
		event.events=EPOLLIN;
		event.data.fd=cdata[i].fdw;
		epoll_ctl(epfd,EPOLL_CTL_ADD,cdata[i].fdw,&event);
	}

	printf("server launch\n");
	int ret1,j;
	int new_fd;
	short flag;
	while(1)
	{
		memset(evs,0,sizeof(event)*(child_count+1));
		ret1=epoll_wait(epfd,evs,child_count+1,-1);
		if(ret1>0)
		{
			for(i=0;i<ret1;i++)
			{
				if(evs[i].data.fd==sfd)
				{
					new_fd=accept(sfd,NULL,NULL);
					for(j=0;j<child_count;j++)
					{
						if(0==cdata[j].busy)
						{
							send_fd(cdata[j].fdw,new_fd);
							cdata[j].busy=1;
							break;
						}
					}
					close(new_fd);
				}else{
					for(j=0;j<child_count;j++)
					{
						if(evs[i].data.fd==cdata[j].fdw)
						{
							read(cdata[j].fdw,&flag,sizeof(flag));
							cdata[j].busy=0;
						}
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
