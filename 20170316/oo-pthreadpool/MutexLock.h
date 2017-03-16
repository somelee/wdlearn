 ///
 /// @file    MutexLock.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-14 23:48:27
 ///
 
#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock
:Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr();

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

}


#endif
