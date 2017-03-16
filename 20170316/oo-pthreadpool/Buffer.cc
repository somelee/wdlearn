 ///
 /// @file    Buffer.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-15 11:50:17
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
	_mutex.lock();
	while(full())
		_notFull.wait();

	_que.push(elem);
	_notEmpty.notify();

	_mutex.unlock();
}

ElemType Buffer::pop()
{
	_mutex.lock();
	while(empty())
		_notEmpty.wait();

	ElemType ret = _que.front();
	_que.pop();

	_notFull.notify();
	_mutex.unlock();

	return ret;
}
}
