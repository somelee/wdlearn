 ///
 /// @file    TimerThread.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 19:37:39
 ///
 
#include "TimerThread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

TimerThread::TimerThread(int initTime,int intervalTime,TimerCallback cb)
:_timer(initTime,intervalTime,cb)
,_thread(std::bind(&Timer::start,&_timer))
{}

TimerThread::~TimerThread()
{
	if(_timer._isStarting())
		stop();
}

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	if(_timer._isStarting())
		_timer.stop();
	_thread.join();
}

}
