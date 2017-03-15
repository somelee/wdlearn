 ///
 /// @file    virtual.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-09 20:38:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual
	int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};

class Sub
:public Base
{
public:
	virtual
		int func(int x)
		{
			cout << "Sub::func(int)" << endl;
			return x;
		}
};

int main()
{
	return 0;
}
