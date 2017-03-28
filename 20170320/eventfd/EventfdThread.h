 ///
 /// @file    EventfdThread.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 23:39:53
 ///
 
#ifndef __WD_EVENTFDTHREAD_H__
#define __WD_EVENTFDTHREAD_H__

#include "Eventfd.h"
#include "Thread.h"

namespace wd
{

class EventfdThread
{
public:
	typedef std::function<void()> EventfdCallback;
	EventfdThread(EventfdCallback cb);

	~EventfdThread();

	void start();
	void stop();
	void wakeup();

private:
	Eventfd _event;
	Thread _thread;
};

}

#endif
