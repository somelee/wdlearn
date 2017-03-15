 ///
 /// @file    protected.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-10 14:33:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
protected:
	Base(int ix)
	:_ix(ix)
	{}

public:
	void display()
	{
		cout << "Base::_ix = " << endl;
	}

private:
	int _ix;
};

class Child
:public Base
{
public:
	Child(int ix)
	:Base(ix)
	{
		cout << "Child(ix)" << endl;
	}


};

int main()
{
//	Base base(1);
	 
}
