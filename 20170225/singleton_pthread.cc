 ///
 /// @file    singleton_pthread.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 11:39:11
 ///
 
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		cout << __FUNCTION__ << endl;
		pthread_once(&once,init);
		return _pInstance;
	}

	static void init()
	{
		cout << __FUNCTION__ << endl;
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			atexit(destroy);
		}
	}

	static void destroy()
	{
		cout << __FUNCTION__ << endl;
		if(_pInstance)
		{
			delete _pInstance;
		}
	}
private:
	Singleton()
	{
		cout << __FUNCTION__ << endl;
	}

	~Singleton()
	{
		cout << __FUNCTION__ << endl;
	}
private:
	static Singleton * _pInstance;
	static pthread_once_t once;
};

Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton::once = PTHREAD_ONCE_INIT;

int main()
{
	cout << __FUNCTION__ << endl;
	Singleton * s1 = Singleton::getInstance();
	Singleton * s2 = Singleton::getInstance();

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	return 0;
}
