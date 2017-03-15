 ///
 /// @file    weak_str2.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 20:15:04
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;

class X
{
public:
	X()
	{
		cout << "X()" << endl;
	}

	~X()
	{
		cout << "~X()" << endl;
	}

	void fun()
	{
		cout << "X::fun()" << endl;
	}
};

int main()
{
	weak_ptr<X> p;
	{
		shared_ptr<X> p2(new X);

		cout << "p2` use_count() = " << p2.use_count() << endl;

		p = p2;

		cout << "p`s use_count() = " << p.use_count() << endl;
		shared_ptr<X> p3 = p.lock();
		if(p3)
		{
			p3->fun();
		}else{
			cout << "X has been destory!" << endl;
		}
		cout << "p2` use_count() = " << p2.use_count() << endl;
	}
	cout << "推出语句块" << endl;

	shared_ptr<X> p4 = p.lock();
	if(p4)
	{
		p4->fun();
	}else{
		cout << "X has been destory!" << endl;
	}
}
