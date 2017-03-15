 ///
 /// @file    oversee.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 23:37:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	int func(int i)
	{
		return _ix;
	}
protected:
	int _ix;
};

class Derived
:public Base
{
public:
	int func(int i)
	{
		_ix = 9;
		Base::_ix = 22;
		cout << "Base::_ix = " << Base::_ix << endl;
		cout << "Derived::_ix = " << Derived::_ix << endl;
		return this->_ix;
	}
public:
	int _ix;
};

int main()
{
	Derived d;
	cout << d.func(1) << endl;
	cout << d.Base::func(1) << endl;

}
