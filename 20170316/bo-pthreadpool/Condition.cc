 ///
 /// @file    Condition.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-17 09:44:56
 ///
 
#include "Condition.h"
#include "MutexLock.h"

namespace wd
{

Condition::Condition(MutexLock & mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}

}
