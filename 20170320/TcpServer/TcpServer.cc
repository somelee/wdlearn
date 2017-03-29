 ///
 /// @file    TcpServer.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 11:11:19
 ///
 
#include "TcpServer.h"

namespace 
{

int createSockFd()
{
	int fd = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(fd == -1)
	{
		fprintf(stderr,"create socket fd error\n");
		exit(EXIT_FAILURE);
	}
	return fd;
}

}

namespace wd
{

TcpServer::TcpServer(const string & ip,unsigned short port)
:_addr(ip,port)
,sockfd_(createSockFd())
,poller_(sockfd_.fd())
{
	sockfd_.setTcpNoDelay(false);
	sockfd_.setReusePort(true);
	sockfd_.setReuseAddr(true);
	sockfd_.setKeepAlive(false);

	sockfd_.bindAddress(_addr);
	sockfd_.listen();
}

}
