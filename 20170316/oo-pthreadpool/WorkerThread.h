 ///
 /// @file    WorkerThread.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 15:43:11
 ///
 
#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__

#include "Thread.h"

namespace wd
{

class Threadpool;

class WorkerThread
:public Thread
{
public:
	WorkerThread(Threadpool & Threadpool);

	void run();

private:
	Threadpool & _threadpool;
};

}

#endif
