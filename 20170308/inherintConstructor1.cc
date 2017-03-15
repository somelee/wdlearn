 ///
 /// @file    inherintConstructor1.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 21:33:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
#if 1
	Base()
	{
		cout << "Base()" << endl;
	}
#endif

	Base(int i)
	{
		cout << "Base(int)" << endl;
	}

};

class Derived
:public Base
{
public:
#if 1
	Derived()
	{
		cout << "Derived()" << endl;
	}

	Derived(int i,int j)
	:Base(i)
	,_drived(j)
	{
		cout << "Derived(int)" << endl;
	}
#endif
private:
	int _drived;
};

int main()
{
	Derived d1(1,2);

	return 0;
}
