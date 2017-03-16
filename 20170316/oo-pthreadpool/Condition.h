 ///
 /// @file    Condition.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-15 00:07:04
 ///
 
#ifndef __WD_CONDTION_H__
#define __WD_CONDTION_H__

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
