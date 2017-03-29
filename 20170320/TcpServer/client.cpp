 ///
 /// @file    client.cpp
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-29 16:27:01
 ///
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "error.h"

int main()
{
	int fd = socket(PF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr = {AF_INET,htons(9999),inet_addr("192.168.175.128")};
	connect(fd,(struct sockaddr *)&addr,sizeof(addr));
	char sen[1024] = {};

		int nread = read(fd,sen,sizeof(sen));
		printf("get:%d bytes,receive:%s",nread,sen);

	while(1)
	{
		memset(sen,0,sizeof(sen));
		fgets(sen,sizeof(sen),stdin);
		printf("----send : %s",sen);
		write(fd,sen,strlen(sen));
		int nread = read(fd,sen,sizeof(sen));
		printf("----get:%d bytes,receive:%s",nread,sen);
	}
}
