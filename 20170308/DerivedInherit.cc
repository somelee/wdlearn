 ///
 /// @file    DerivedInherit.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 20:58:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	void print()
	{
		cout << "A::print()" << endl;
	}
};

class B
{
public:
	void print()
	{
		cout << "B::print()" << endl;
	}
};

class C
:public A
,public B
{
public:
	void display()
	{
		cout << "C::display()" << endl;
	}
};

int main()
{
	C c;
	c.A::print();
	c.B::print();
	c.display();

	return 0;
}
