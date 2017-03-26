 ///
 /// @file    client.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-26 21:20:28
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

void do_service(int sockfd);

int main(int argc,const char *argv[])
{
	int peerfd = socket(PF_INET,SOCK_STREAM,0);
	if(peerfd == -1)
		ERR_EXIT("socket");

	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.175.128");
	addr.sin_port = htons(8888);
	socklen_t len = sizeof addr;
	if(connect(peerfd,(struct sockaddr*)&addr,len) == -1)
		ERR_EXIT("Connect");

	do_service(peerfd);

	return 0;
}

void do_service(int sockfd)
{
	char recvbuf[1024] = {0};
	char sendbuf[1024] = {0};
	while(1)
	{
		fgets(sendbuf,sizeof(sendbuf),stdin);
		write(sockfd,sendbuf,strlen(sendbuf));

		int nread = read(sockfd,recvbuf,sizeof(recvbuf));
		if(nread == -1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("read");
		}else if(nread == 0){
			printf("server close!\n");
			close(sockfd);
			exit(EXIT_SUCCESS);
		}

		printf("receive msg : %s",recvbuf);

		memset(recvbuf,0,sizeof(recvbuf));
		memset(sendbuf,0,sizeof(sendbuf));
	}
}


