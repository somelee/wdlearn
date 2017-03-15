 ///
 /// @file    constructor.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-10 10:30:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base0
{
public:
	Base0()
	{
		cout << "Base0()" << endl;
	}

	~Base0()
	{
		cout << "~Base0()" << endl;
	}

	virtual void func1()
	{
		cout << "Base0::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Base0::func2()" << endl;
	}
};

class Base1
:public Base0
{
public:
	Base1()
	{
		cout << "Base1()" << endl;
		func1();
	}

	~Base1()
	{
		func2();
		cout << "~Base1()" << endl;
	}

	void func2()
	{
		cout << "Base1::func2()" << endl;
	}
};

class Sub
:public Base1
{
public:
	Sub()
	{
		cout << "Sub()" << endl;
	}

	~Sub()
	{
		cout << "~Sub()" << endl;
	}

	void func1()
	{
		cout << "Sub::func1()" << endl;
	}

	void func2()
	{
		cout << "Sub::func2()" << endl;
	}
};

int main()
{
	Sub sub;
	return 0;
}
