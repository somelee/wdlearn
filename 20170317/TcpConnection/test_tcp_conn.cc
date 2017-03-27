 ///
 /// @file    test_tcp_conn.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-26 20:19:09
 ///
 
#include "Socket.h"
#include "TcpConnection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc,char const *argv[])
{
	int fd = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(fd == -1)
	{
		perror("create socket error");
		exit(EXIT_FAILURE);
	}

	wd::InetAddress addr("192.168.175.128",8888);

	wd::Socket sock(fd);
	sock.ready(addr);

	int peerfd = sock.accept();

	wd::TcpConnectionPtr conn(new wd::TcpConnection(peerfd));

	cout << conn->toString() << endl;
	while(1)
	{
		std::string msg(conn->receive());
		if(msg.size() == 0)
			conn->shutdown();
		std::cout << msg << endl;
		conn->send(msg);
	}

	conn->shutdown();
	close(fd);

	return 0;
}
