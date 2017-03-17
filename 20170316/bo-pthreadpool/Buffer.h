 ///
 /// @file    Buffer.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 22:29:44
 ///
 
#ifndef __WD_BUFFER_H__
#define __WD_BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
#include <functional>

namespace wd
{

typedef std::function<void()> ElemType;

class Buffer
{
public:
	Buffer(size_t size);

	void push(ElemType elem);
	ElemType pop();

	void wakeup();

	bool empty();
	bool full();

private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _size;
	std::queue<ElemType> _que;
	bool _flag;
};

}

#endif
