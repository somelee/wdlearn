 ///
 /// @file    pure.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-10 11:35:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual void display() = 0;
};

class B
:public A
{
public:
	virtual void display()
	{
		cout << "B::display()" << endl;
	}
};

int main()
{
	A *p = new B;
	p->display();

	return 0;
}
