 ///
 /// @file    Timer.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 17:03:50
 ///
 
#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include "Noncopyable.h"
#include <functional>

namespace wd
{

class Timer
:public Noncopyable
{
public:
	typedef std::function<void()> TimerCallback;

	Timer(int initTime,int intervalTime,TimerCallback cb);
	~Timer();

	void start();
	void stop();
	bool _isStarting() const
	{	return _isStarted;	}

private:
	int createTimerFd();
	void setTimerFd(int initTime,int intervalTime);
	void stopTimerFd();
	void readTimerFd();

private:
	int _fd;
	int _initTime;
	int _intervalTime;
	TimerCallback _cb;
	bool _isStarted;
};

}

#endif
