 ///
 /// @file    singleton.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-04 16:50:34
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton
{
public:

	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

	void display()
	{
		cout << "Singleton::display()" << endl;
	}

private:
	static Singleton * _pInstance;

	Singleton()
	{}
};

Singleton * Singleton::_pInstance = NULL;

int main()
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	return 0;
}
