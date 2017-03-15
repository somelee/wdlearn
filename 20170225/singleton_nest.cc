 ///
 /// @file    singleton_nest.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 10:22:36
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << __FUNCTION__ << endl;
		}

		~AutoRelease()
		{
			cout << __FUNCTION__ << endl;
			if(Singleton::_pInstance)
			{
				delete Singleton::_pInstance;
			}
		}
	};
public:
	static Singleton * getInstance()
	{
		cout << __FUNCTION__ << endl;
//		if(NULL == _pInstance)
//		{
//			_pInstance = new Singleton;
//		}
		return _pInstance;
	}

	void print()
	{
		cout << __FUNCTION__ << endl;
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
	static AutoRelease _ar;
};

//Singleton * Singleton::_pInstance = NULL;
Singleton * Singleton::_pInstance = new Singleton;
Singleton::AutoRelease Singleton::_ar;

int main()
{
	cout << __FUNCTION__ << endl;

	Singleton * s1 = Singleton::getInstance();
	Singleton * s2 = Singleton::getInstance();


	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	return 0;
}
