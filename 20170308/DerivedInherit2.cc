 ///
 /// @file    DerivedInherit2.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 21:06:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(int ix = 0)
	:_ix(ix)
	{
		cout << "A(int)" << endl;
	}

	void setX(int ix)
	{
		_ix = ix;
	}

	void print()
	{
		cout << "A::_ix = " << _ix << endl;
	}

	int getX()
	{
		return _ix;
	}
private:
	int _ix;
};

class B
:virtual public A
{
public:
	void print()
	{
		cout << "B::A::_ix = " << getX() << endl;
	}

};

class C
:virtual public A
{
public:
	void print()
	{
		cout << "C::A::_ix = " << getX() << endl;
	}
};

class D
:public B
,public C
{};

int main()
{
	D d;
	d.B::print();
	d.C::print();
	cout << "sizeof(D) = " << sizeof(D) << endl;
	d.setX(1);

	cout << endl;
	d.B::print();
	d.C::print();

	return 0;
}
