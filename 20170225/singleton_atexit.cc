 ///
 /// @file    singleton_atexit.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 11:19:55
 ///
 
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
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy()
	{
		cout << __FUNCTION__ << endl;
		delete _pInstance;
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
};

Singleton * Singleton::_pInstance = NULL;

int main()
{
	Singleton * s1 = Singleton::getInstance();
	Singleton * s2 = Singleton::getInstance();

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	return 0;
}
