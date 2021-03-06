 ///
 /// @file    test_epoll.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-27 20:36:46
 ///
 
#include "Socket.h"
#include "TcpConnection.h"
#include "EpollPoller.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void onConnection(const wd::TcpConnectionPtr &conn)
{
	printf("%s\n",conn->toString().c_str());
	conn->send("hello,welcome to Chat Server.\r\n");
}

void onMessage(const wd::TcpConnectionPtr &conn)
{
	std::string s(conn->receive());
	conn->send(s);
}

void onClose(const wd::TcpConnectionPtr &conn)
{
	printf("%s close\n",conn->toString().c_str());
}

int main(int argc,char const *argv[])
{
	int fd = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(fd == -1)
	{
		perror("create socket error");
		exit(EXIT_FAILURE);
	}

	wd::InetAddress addr("192.168.175.128",9999);

	wd::Socket sock(fd);
	sock.ready(addr);

	wd::EpollPoller poller(fd);
	poller.setConnectCallback(&onConnection);
	poller.setMessageCallback(&onMessage);
	poller.setCloseCallback(&onClose);

	poller.loop();

	return 0;
}
