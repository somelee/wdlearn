 ///
 /// @file    Threadpool.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 15:27:07
 ///
 
#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "Buffer.h"
#include "Task.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

namespace wd
{

class Thread;

class Threadpool
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum,size_t _bufSize);
	~Threadpool();

	void start();
	void stop();

	void addTask(Task *);

private:
	Task * getTask();
	void processTask();
private:
	bool _isExit;
	size_t _threadNum;
	size_t _bufSize;
	Buffer _buff;
	vector<shared_ptr<Thread>> _threads;
};

}

#endif
