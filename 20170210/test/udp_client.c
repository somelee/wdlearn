 ///
 /// @file    udp_client.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-10 18:27:01
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
	sfd=socket(AF_INET,SOCK_DGRAM,0);
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
	ret=sendto(sfd,"I am client",11,0,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("sendto");
		return -1;
	}
	char buf[20]={};
	int addrlen=sizeof(ser);
	ret=recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&ser,&addrlen);
	if(-1==ret)
	{
		perror("recvfrom");
		return -1;
	}
	printf("buf=%s\n",buf);
	close(sfd);
	return 0;
}
