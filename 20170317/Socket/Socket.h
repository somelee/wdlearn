 ///
 /// @file    Socket.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-25 15:22:46
 ///
 
#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{

class Socket
:private Noncopyable
{
public:
	explicit Socket(int sockfd);
	Socket();
	~Socket();

	void ready(const InetAddress & inetAddr);

	int fd() const
	{	return sockfd_;	}
	void bindAddress(const InetAddress &addr);
	void listen();
	int accept();

	void shutdownWrite();

	void setReuseAddr(bool on);
	void setReusePort(bool on);

	static InetAddress getLocalAddr(int sockfd);
	static InetAddress getPeerAddr(int sockfd);

private:
	int sockfd_;
};

}

#endif
