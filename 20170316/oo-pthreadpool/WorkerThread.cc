 ///
 /// @file    WorkerThread.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 15:47:51
 ///
 
#include "WorkerThread.h"
#include "Threadpool.h"

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
:_threadpool(threadpool)
{}

void WorkerThread::run()
{
	_threadpool.processTask();
}

}
