 ///
 /// @file    virtual2.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-09 20:46:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
//	virtual
	void display()
	{
		cout << "Base::display()" << endl;
	}
private:
	double _d0;
};

class Child1
:public Base
{
public:
//	virtual
	void display()
	{
		cout << "Child1::display()" << endl;
	}
private:
	double _d1;
};

class Child2
:public Base
{
public:
//	virtual
	void display()
	{
		cout << "Child2::display()" << endl;
	}
private:
	double _d2;
};

void display(Base * pb)
{
	pb->display();
}

int main()
{
	Base base;
	Child1 child1;
	Child2 child2;

	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Child1) = " << sizeof(Child1) << endl;
	cout << "sizeof(Child2) = " << sizeof(Child2) << endl;
//	display(&base);
//	display(&child1);
//	display(&child2);

	return 0;
}
