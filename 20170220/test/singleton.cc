#include <iostream> 
#include <stdio.h>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstence)
		{
			_pInstence = new Singleton;
		}
		return _pInstence;
	}

	static void destory()
	{
		delete _pInstence;
	}
private:
	Singleton(){}
	~Singleton(){}
private:
	static Singleton * _pInstence;
};

Singleton *Singleton::_pInstence = NULL;

int main()
{
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout << "p1=" << p1 << endl;
	cout << "p2=" << p2 << endl;
	Singleton::destory();

	return 0;
}
