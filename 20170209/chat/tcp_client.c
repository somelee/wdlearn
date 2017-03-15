 ///
 /// @file    tcp_client.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-09 20:40:43
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
	ret=connect(fds,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	char buf[50]={};
	fd_set rdset;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(fds,&rdset);
		ret=select(fds+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(STDIN_FILENO,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(ret<=0)
				{
					printf("client over\n");
					break;
				}
				ret=send(fds,buf,strlen(buf)-1,0);
				if(-1==ret)
				{
					perror("send");
					return -1;
				}
			}
			if(FD_ISSET(fds,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=recv(fds,buf,sizeof(buf),0);
				if(-1==ret)
				{
					perror("recv");
					return -1;
				}else if(0==ret)
				{
					printf("Bye Bye\n");
					break;
				}
				printf("%s\n",buf);
			}
		}
	}
	close(fds);
	return 0;
}
