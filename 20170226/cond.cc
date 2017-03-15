 ///
 /// @file    cond.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 17:21:05
 ///
 
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using std::endl;
using std::cout;

class MutexLock
{
public:
	MutexLock()
	:_isLocking(false)
	{
		cout << __FUNCTION__ << endl;
		pthread_mutex_init(&_mutex,NULL);
	}

	~MutexLock()
	{
		cout << __FUNCTION__ << endl;
		pthread_mutex_destroy(&_mutex);
	}

	void lock()
	{
		cout << __FUNCTION__ << endl;
		pthread_mutex_lock(&_mutex);
		_isLocking = true;
	}

	void unlock()
	{
		cout << __FUNCTION__ << endl;
		pthread_mutex_unlock(&_mutex);
		_isLocking = false;
	}

	pthread_mutex_t * getMutexLockPtr()
	{
		cout << __FUNCTION__ << endl;
		return &_mutex;
	}

	bool MutexStatus() const
	{
		cout << __FUNCTION__ << endl;
		return _isLocking;
	}

private:
	MutexLock(const MutexLock &);
	MutexLock & operator=(const MutexLock &);
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class Condition
{
public:
	Condition(MutexLock & mutex)
	:_mutex(mutex)
	{
		cout << __FUNCTION__ << endl;
		pthread_cond_init(&_cond,NULL);
	}

	~Condition()
	{
		cout << __FUNCTION__ << endl;
		pthread_cond_destroy(&_cond);
	}

	void wait()
	{
		cout << __FUNCTION__ << endl;
		pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
	}

	void notify()
	{
		cout << __FUNCTION__ << endl;
		pthread_cond_signal(&_cond);
	}

	void notifyall()
	{
		cout << __FUNCTION__ << endl;
		pthread_cond_broadcast(&_cond);
	}
private:
	Condition();
	Condition & operator=(const Condition &);

private:
	MutexLock & _mutex;
	pthread_cond_t _cond;
};

int main()
{
	cout << __FUNCTION__ << endl;

	MutexLock mutex;
	Condition cond(mutex);

	mutex.lock();
	cond.wait();
	cond.notify();
	mutex.unlock();

	return 0;
}
