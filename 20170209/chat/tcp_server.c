 ///
 /// @file    tcp_server.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-09 21:12:44
 ///
 
#include "func.h"

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("args error\n");
		return -1;
	}
	int fds=socket(AF_INET,SOCK_STREAM,0);
	if(-1==fds)
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
	ret=bind(fds,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	listen(fds,10);
	struct sockaddr_in cli;
	memset(&cli,0,sizeof(cli));
	char buf[50]={};
	fd_set rdset,tempset;
	int new_fd=-1;
	FD_ZERO(&tempset);
	FD_SET(STDIN_FILENO,&tempset);
	FD_SET(fds,&tempset);
	while(1)
	{
		FD_ZERO(&rdset);
		memcpy(&rdset,&tempset,sizeof(fd_set));
		ret=select(13,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(fds,&rdset))
			{
				int addlen=sizeof(cli);
				new_fd=accept(fds,(struct sockaddr*)&cli,&addlen);
				if(-1==new_fd)
				{
					perror("accept");
					return -1;
				}
				printf("client ip=%s,client port=%d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
				FD_SET(new_fd,&tempset);
			}
			if(FD_ISSET(STDIN_FILENO,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(ret<=0)
				{
					printf("Bye bye\n");
					close(new_fd);
					FD_CLR(new_fd,&tempset);
					continue;
				}
				ret=send(new_fd,buf,strlen(buf)-1,0);
				if(-1==ret)
				{
					perror("send");
					return -1;
				}
			}
			if(FD_ISSET(new_fd,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=recv(new_fd,buf,sizeof(buf),0);
				if(-1==ret)
				{
					perror("recv");
					return -1;
				}else if(0==ret)
				{
					printf("Bye Bye\n");
					close(new_fd);
					FD_CLR(new_fd,&tempset);
					continue;
				}
				printf("%s\n",buf);
			}
		}
	}
	close(fds);
	return 0;
}
