 ///
 /// @file    Threadpool.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 15:34:26
 ///
 
#include "Threadpool.h"
#include "WorkerThread.h"
#include "Task.h"
#include <unistd.h>

namespace wd
{

Threadpool::Threadpool(size_t threadNum,size_t bufSize)
:_isExit(false)
,_threadNum(threadNum)
,_bufSize(bufSize)
,_buff(_bufSize)
{
	_threads.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
		stop();
}

void Threadpool::start()
{
	for(size_t idx = 0;idx != _threadNum;++idx)
	{
		shared_ptr<Thread> sp(new WorkerThread(*this));
		_threads.push_back(sp);
		sp->start();
	}
}

void Threadpool::stop()
{
	if(!_isExit)
	{
		while(!_buff.empty())
		{
			sleep(1);
		}

		_isExit = true;
		for(auto & elem : _threads)
		{
			elem->join();
		}
	}
}

void Threadpool::addTask(Task * ptask)
{
	_buff.push(ptask);
}

Task * Threadpool::getTask()
{
	return _buff.pop();
}

void Threadpool::processTask()
{
	while(!_isExit)
	{
		Task * ptask = getTask();

		if(ptask)
			ptask->execute();
	}
}

}

