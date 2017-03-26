 ///
 /// @file    Socket.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-26 14:45:22
 ///
 
#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{

class Socket
:Noncopyable
{
public:
	explicit Socket(int sockfd);
	~Socket();

	void ready(const InetAddress &);

	int fd() const {	return sockfd_;	}
	void bindAddress(const InetAddress &addr);
		void listen();
	int accept();

	void shutdownWrite();

	void setTcpNoDelay(bool on);
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void setKeepAlive(bool on);

	static InetAddress getLocalAddr(int sockfd);
	static InetAddress getPeerAddr(int sockfd);
private:
	const int sockfd_;
};

}

#endif
