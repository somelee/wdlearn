 ///
 /// @file    udp_server.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-10 10:44:17
 ///

#include "func.h"

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("args erro\n");
		return -1;
	}
	int sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
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
	struct sockaddr_in cli;
	memset(&cli,0,sizeof(cli));
	int addrlen=sizeof(cli);
	char buf[20]={};
	ret=recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&cli,&addrlen);
	if(-1==ret)
	{
		perror("recvfrom");
		return -1;
	}
	printf("cli IP=%s,cli port=%d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
	printf("buf=%s\n",buf);
	ret=sendto(sfd,"I am server",11,0,(struct sockaddr*)&cli,sizeof(cli));
	if(-1==ret)
	{
		perror("recyfrom");
		return -1;
	}
	close(sfd);
	return 0;
}
