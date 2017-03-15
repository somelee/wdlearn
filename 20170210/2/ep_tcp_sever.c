 ///
 /// @file    ep_tcp_sever.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-10 19:08:58
 ///
 
#include "func.h"

void change_noblock(int fd)
{
	int status;
	status=fcntl(fd,F_GETFL);
	status=status|O_NONBLOCK;
	int ret=fcntl(fd,F_SETFL,status);
	if(-1==ret)
	{
		perror("fcntl");
		return;
	}
}

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("args error\n");
		return -1;
	}
	int sfd=socket(AF_INET,SOCK_STREAM,0);
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
	ret=bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,10);
	int epfd=epoll_create(1);
	struct epoll_event event,evs[3];
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
	struct sockaddr_in cli;
	memset(&cli,0,sizeof(cli));
	char buf[5]={};
	char buf1[20]={};
	int new_fd=-1;
	int i,ret1;
	while(1)
	{
		memset(evs,0,sizeof(evs));
		ret1=epoll_wait(epfd,evs,3,-1);
		if(ret1>0)
		{
			for(i=0;i<ret1;i++)
			{
				if(sfd==evs[i].data.fd)
				{
					int addrlen=sizeof(cli);
					new_fd=accept(sfd,(struct sockaddr*)&cli,&addrlen);
					if(-1==new_fd)
					{
						perror("accept");
						return -1;
					}
					printf("client IP=%s,port=%d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
					change_noblock(new_fd);
					memset(&event,0,sizeof(event));
					event.events=EPOLLIN|EPOLLET;
					event.data.fd=new_fd;
					ret=epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&event);
				}
				if(new_fd==evs[i].data.fd)
				{
					while(1)
					{
						memset(&evs,0,sizeof(evs));
						ret=recv(new_fd,buf,sizeof(buf),0);
						if(-1==ret && errno==EAGAIN)
						{
							break;
						}else if(0==ret)
						{
							printf("Bye Bye");
							close(new_fd);
							memset(&event,0,sizeof(event));
							event.events=EPOLLIN;
							event.data.fd=new_fd;
							ret=epoll_ctl(epfd,EPOLL_CTL_DEL,new_fd,&event);
							break;
						}
						printf("%s",buf);
					}
					printf("\n");
				}
				if(evs[i].events==EPOLLIN && evs[i].data.fd==0)
				{
					memset(buf1,0,sizeof(buf1));
					ret=read(STDIN_FILENO,buf,sizeof(buf1));
					if(ret<=0)
					{
						printf("Bye Bye\n");
						close(new_fd);
						memset(&event,0,sizeof(event));
						event.events=EPOLLIN;
						event.data.fd=new_fd;
						ret=epoll_ctl(epfd,EPOLL_CTL_DEL,new_fd,&event);
						continue;
					}
					ret=send(new_fd,buf1,strlen(buf1)-1,0);
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
