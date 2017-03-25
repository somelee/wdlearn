 ///
 /// @file    SocketIO.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-25 17:09:47
 ///
 
#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__

#include "Noncopyable.h"
#include <sys/types.h>

namespace wd
{

class SocketIO
:Noncopyable
{
public:
	explicit SocketIO(int sockfd)
	:sockfd_(sockfd)
	{}

	ssize_t readn(char *buf,size_t count);
	ssize_t writen(const char *buf,size_t count);
	ssize_t readline(char *usrbuf,size_t maxlen);
private:
	ssize_t recv_peek(char *buf,size_t len);

	const int sockfd_;
};

}

#endif
