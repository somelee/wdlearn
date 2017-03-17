 ///
 /// @file    Condition.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-17 09:40:49
 ///
 
#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock;

class Condition
:Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}

#endif
