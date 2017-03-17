 ///
 /// @file    Threadpool.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-17 18:49:38
 ///
 
#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "Buffer.h"

#include <vector>
#include <memory>
#include <functional>

using std::vector;
using std::shared_ptr;

namespace wd
{

class Thread;

typedef std::function<void()> Task;

class Threadpool
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum,size_t bufSize);
	~Threadpool();

	void start();
	void stop();

	void addTask(Task task);

private:
	Task getTask();
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
