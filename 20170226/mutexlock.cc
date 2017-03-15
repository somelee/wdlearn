 ///
 /// @file    mutexlock.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 14:58:20
 ///
 
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

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

int main()
{
	cout << __FUNCTION__ << endl;

	MutexLock mutex;
	cout << "mutex status :" << mutex.MutexStatus() << endl;

	mutex.lock();
	cout << "mutex status :" << mutex.MutexStatus() << endl;

	mutex.unlock();
	cout << "mutex status :" << mutex.MutexStatus() << endl;

	return 0;
}
