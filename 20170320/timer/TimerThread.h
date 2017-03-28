 ///
 /// @file    TimerThread.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 17:32:58
 ///
 
#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "Timer.h"
#include "Thread.h"

namespace wd
{

class TimerThread
{
public:
	typedef std::function<void()> TimerCallback;
	TimerThread(int initTime,int intervalTime,TimerCallback cb);

	~TimerThread();

	void start();
	void stop();

private:
	Timer _timer;
	Thread _thread;
};

}

#endif
