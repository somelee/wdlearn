 ///
 /// @file    ep_tcp_client.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-10 21:04:31
 ///
 
#include "func.h"

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("args error\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	char buf[20]={};
	int epfd=epoll_create(1);
	struct epoll_event event,evs[2];
	memset(&event,0,sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=sfd;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	memset(&event,0,sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=STDIN_FILENO;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	int i,ret1;
	while(1)
	{
		memset(evs,0,sizeof(evs));
		ret1=epoll_wait(epfd,evs,2,-1);
		if(ret1>0)
		{
			for(i=0;i<ret1;i++)
			{
				if(evs[i].data.fd==sfd)
				{
					memset(buf,0,sizeof(buf));
					ret=recv(sfd,buf,sizeof(buf),0);
					if(-1==ret)
					{
						perror("recv");
						return -1;
					}else if(0==ret)
					{
						printf("Bye Bye\n");
						close(sfd);
						return 0;
					}
					printf("%s\n",buf);
				}
				if(evs[i].data.fd==STDIN_FILENO)
				{
					memset(buf,0,sizeof(buf));
					ret=read(0,buf,sizeof(buf));
					if(ret<=0)
					{
						printf("Bye Bye\n");
						close(sfd);
						return 0;
					}
					ret=send(sfd,buf,strlen(buf)-1,0);
					if(-1==ret)
					{
						perror("send");
						return -1;
					}
				}
			}
		}
	}
	close(sfd);
	return 0;
}
