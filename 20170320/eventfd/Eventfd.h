 ///
 /// @file    Eventfd.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 21:50:44
 ///
 
#ifndef __WD_EVENTFD_H__
#define __WD_EVENTFD_H__

#include "Noncopyable.h"
#include <functional>

namespace wd
{

class Eventfd
:public Noncopyable
{
public:
	typedef std::function<void()> EventfdCallback;

	Eventfd(EventfdCallback cb);
	~Eventfd();

	void start();
	void stop();
	bool isStarting() const
	{	return _isStarted;	}

	void wakeup();

private:
	int createEventFd();
	void handleRead();
private:
	int _fd;
	EventfdCallback _cb;
	bool _isStarted;
};

}

#endif
