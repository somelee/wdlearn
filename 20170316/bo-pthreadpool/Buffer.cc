 ///
 /// @file    Buffer.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-17 09:56:45
 ///
 
#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Buffer::Buffer(size_t size)
:_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
,_size(size)
,_flag(true)
{}

bool Buffer::empty()
{
	return _que.size() == 0;
}

bool Buffer::full()
{
	return _que.size() == _size;
}

void Buffer::push(ElemType elem)
{
	MutexLockGuard guard(_mutex);
	while(full())
		_notFull.wait();

	_que.push(elem);
	_notEmpty.notify();
}

ElemType Buffer::pop()
{
	MutexLockGuard guard(_mutex);
	while(_flag && empty())
		_notEmpty.wait();

	if(_flag)
	{
		ElemType ret = _que.front();
		_que.pop();

		_notFull.notify();
		return ret;
	}else
		return NULL;
}

void Buffer::wakeup()
{
	_flag = false;
	_notEmpty.notifyall();
}

}
