 ///
 /// @file    Thread.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-15 12:29:22
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread
:private Noncopyable
{
public:
	Thread();
	virtual ~Thread();

	virtual void run() = 0;

	void start();
	void join();

	static void * threadFunc(void * arg);
private:
	pthread_t _pthId;
	bool _isRunning;
};

}

#endif
