 ///
 /// @file    EpollPoller.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-27 15:23:20
 ///
 
#ifndef __EPOLL_POLLER_H__
#define __EPOLL_POLLER_H__

#include "Noncopyable.h"
#include <vector>
#include <map>
#include <sys/epoll.h>
#include "TcpConnection.h"

namespace wd
{

class EpollPoller
:Noncopyable
{
public:
	typedef TcpConnection::TcpConnectionCallback EpollCallback;

	explicit EpollPoller(int listenfd);
	~EpollPoller();

	void loop();
	void unloop();

	void setConnectCallback(EpollCallback cb)
	{	onConnectCallback_ = std::move(cb);	}
	void setMessageCallback(EpollCallback cb)
	{	onMessageCallback_ = std::move(cb);	}
	void setCloseCallback(EpollCallback cb)
	{	onCloseCallback_ = std::move(cb);	}

private:
	void waitEpollFd();
	void handleConnection();
	void handleMessage(int peerfd);

private:
	const int epollfd_;
	const int listenfd_;
	bool isLooping_;

	typedef std::vector<struct epoll_event> EventList;
	EventList events_;

	typedef std::map<int,TcpConnectionPtr> ConnectionList;
	ConnectionList lists_;

	EpollCallback onConnectCallback_;
	EpollCallback onMessageCallback_;
	EpollCallback onCloseCallback_;
};

}

#endif
