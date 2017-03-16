 ///
 /// @file    MutexLock.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 22:42:02
 ///
 
#include "MutexLock.h"

namespace wd
{

MutexLock::MutexLock()
:_isLocking(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destory(&_mutex);
}

void MutexLock::lock()
{
	_isLocking = true;
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}
}
