 ///
 /// @file    bind.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 23:33:23
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

int func(int x,int y)
{
	return x + y;
}

class A
{
public:
	int func(int x,int y)
	{
		return x + y;
	}

	int data = 10;
};

void f(int n1,int n2,int n3,const int & n4,int n5)
{
	cout << "(" << n1
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5
		 << ")" << endl;
}

int main()
{
	using namespace std::placeholders;
	auto f1 = std::bind(func,10,20);
	cout << f1() << endl;

	auto f2 = std::bind(func,_1,10);
	cout << f2(20) << endl;

	A a;
	auto f3 = std::bind(&A::func,&a,_1,_2);
	cout << f3(10,20) << endl;

	int n = 7;
	auto f4 = std::bind(f,_2,_1,42,std::cref(n),n);
	n = 10;
	f4(1,2,1001);

	auto f5 = std::bind(&A::data,&a);
	cout << f5() << endl;

	return 0;
}
