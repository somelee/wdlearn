 ///
 /// @file    test_tcp_server.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 11:17:58
 ///
 
#include "TcpServer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

void onConnection(const wd::TcpConnectionPtr &conn)
{
	printf("\n> %s has connected!\n",conn->toString().c_str());
	conn->send("hello,welcome to chat Server.\n");
}

void onMessage(const wd::TcpConnectionPtr &conn)
{
	std::string s(conn->receive());
	cout << "recv msg : " << s << endl;
	conn->sendInLoop(s);
	//conn->send(s);
}

void onClose(const wd::TcpConnectionPtr &conn)
{
	printf("> %s has close.\n",conn->toString().c_str());
}

int main(int argc,char const *argv[])
{
	wd::TcpServer server("192.168.175.128",9999);

	server.setConnectCallback(&onConnection);
	server.setMessageCallback(&onMessage);
	server.setCloseCallback(&onClose);

	cout << "start" << endl;
	server.start();

	return 0;
}
