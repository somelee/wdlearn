 ///
 /// @file    Thread.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 16:46:54
 ///
 
#include "Noncopyable.h"
#include <pthread.h>

#include <functional>
using std::function;

namespace wd
{

class Thread
:private Noncopyable
{
	typedef function<void()> ThreadCallback;
public:
	Thread(ThreadCallback cb);
	~Thread();

	void start();
	void join();

	static void * threadFunc(void * arg);

private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallback _cb;
};

}
