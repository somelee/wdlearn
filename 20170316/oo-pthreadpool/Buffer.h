 ///
 /// @file    Buffer.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-15 11:46:53
 ///
 
#ifndef __WD_BUFFER_H__
#define __WD_BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include "Task.h"
#include <queue>

namespace wd
{

class Task;

typedef Task* ElemType;

class Buffer
{
public:
	Buffer(size_t size);

	void push(ElemType);
	ElemType pop();

	bool empty();
	bool full();

private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _size;
	std::queue<ElemType> _que;
};

}

#endif
