 ///
 /// @file    multi.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-10 15:44:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual void a()
	{
		cout << "A::a()" << endl;
	}

	virtual void b()
	{
		cout << "A::b()" << endl;
	}

	virtual void c()
	{
		cout << "A::c()" << endl;
	}
};

class B
{
public:
	virtual void a()
	{
		cout << "B::a()" << endl;
	}

	virtual void b()
	{
		cout << "B::b()" << endl;
	}

	void c()
	{
		cout << "B::c()" << endl;
	}

	void d()
	{
		cout << "B::d()" << endl;
	}
};

class C
:public A
,public B
{
public:
	virtual void a()
	{
		cout << "C::a()" << endl;
	}

	void c()
	{
		cout << "C::c()" << endl;
	}

	void d()
	{
		cout << "C::d()" << endl;
	}
};

int main()
{
	A a;
	B b;
	C c;

	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

	cout << endl;

	c.A::b();
	c.B::b();

	cout << endl;

	A * pA = &c;
	pA->a();
	pA->b();
	pA->c();
	cout << pA << endl;

	B * pB = &c;
	pB->a();
	pB->b();
	pB->c();
	pB->d();
	cout << pB << endl;
	cout << endl;

	C * pC = &c;
	pC->a();
	pC->c();
	pC->d();

	return 0;

}
