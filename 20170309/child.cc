 ///
 /// @file    child.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-09 23:41:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual void display()
	{
		cout << "Base::display()" << endl;
	}
#if 1
	void print()
	{
		cout << "Base::print()" << endl;
	}
#endif

	void callBase1()
	{
		display();
	}

	void callBase2()
	{
		Base::display();
	}
};

class Child
:public Base
{
public:
	void display()
	{
		cout << "Child::display()" << endl;
	}
#if 1 
	void print()
	{
		cout << "Child::print()" << endl;
	}
#endif
	void callChild1()
	{
		display();
	}
};

int test1()
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Child) = " << sizeof(Child) << endl;
	Base base;
	Base * pbase = &base;
	pbase->display();

	Child child;
	Child * pChild = &child;
	pChild->display();
	cout << endl;

	pbase = & child;
	pbase->display();
	pbase->print();
	cout << endl;

	pChild = (Child*)&base;
	pChild->display();
	pChild->print();
	cout << endl;

	return 0;
}

int test()
{
	Base base;
	Child child;

	Base & ref1 = base;
	ref1.display();

	Base & ref2 = child;
	ref2.display();
}

int main()
{
	Base base;
	Child child;

	base.callBase1();
	child.callChild1();

	cout << endl;

	Base * p1 = &base;
	p1->callBase1();
	p1->callBase2();

	Base * p2 = &child;
	p2->callBase1();
	p2->callBase2();

	return 0;
}
