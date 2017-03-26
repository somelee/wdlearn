 ///
 /// @file    TcpConnection.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-26 17:46:30
 ///
 
#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__

#include "Noncopyable.h"
#include "Socket.h"
#include "SocketIO.h"
#include <memory>
#include <functional>

namespace wd
{

class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection
:Noncopyable
,public std::enable_shared_from_this<TcpConnection>
{
public:
	typedef std::function<void (TcpConnectionPtr &)> TcpConnectionCallback;

	explicit TcpConnection(int sockfd);
	~TcpConnection();

	void shutdown()
	{	
		sockfd_.shutdownWrite();
		isShutdownWrite_ = true;
	}

	ssize_t readn(char *buf,size_t count);
	ssize_t writen(const char *buf,size_t count);
	ssize_t readline(char *usrbuf,size_t maxlen);

	std::string receive();
	void send(const std::string &s);

	const InetAddress &getLocalAddr() const
	{	return localAddr_;	}
	const InetAddress &getPeerAddr() const
	{	return peerAddr_;	}

	std::string toString() const;

private:
	Socket sockfd_;
	SocketIO sockIO_;
	const InetAddress localAddr_;
	const InetAddress peerAddr_;
	bool isShutdownWrite_;
};

}

#endif
