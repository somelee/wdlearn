 ///
 /// @file    TcpServer.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 10:50:41
 ///
 
#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

#include "Noncopyable.h"
#include "EpollPoller.h"
#include "Socket.h"
#include "InetAddress.h"
#include <string>
using std::string;

namespace wd
{

class TcpServer
:Noncopyable
{
public:
	typedef EpollPoller::EpollCallback TcpServerCallback;

	TcpServer(const string & ip,unsigned short port);

	void start()
	{	poller_.loop();	}

	void setConnectCallback(TcpServerCallback cb)
	{	poller_.setConnectCallback(std::move(cb));	}
	void setMessageCallback(TcpServerCallback cb)
	{	poller_.setMessageCallback(std::move(cb));	}
	void setCloseCallback(TcpServerCallback cb)
	{	poller_.setCloseCallback(std::move(cb));	}

private:
	InetAddress _addr;
	Socket sockfd_;
	EpollPoller poller_;
};

}


#endif
