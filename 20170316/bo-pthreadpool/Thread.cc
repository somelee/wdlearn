 ///
 /// @file    Thread.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-17 18:40:40
 ///
 
#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{

Thread::Thread(ThreadCallback cb)
:_pthId(0)
,_isRunning(false)
,_cb(cb)
{}

void Thread::start()
{
	pthread_create(&_pthId,NULL,threadFunc,this);
	_isRunning = true;
}

void * Thread::threadFunc(void * arg)
{
	Thread * p = static_cast<Thread*>(arg);
	if(p)
		p->_cb();
	return NULL;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId,NULL);
		_isRunning = false;
	}
}

Thread::~Thread()
{
	cout << "~Thread()" << endl;
	if(_isRunning)
	{
		pthread_detach(_pthId);
		_isRunning = false;
	}
}

}
