 ///
 /// @file    default.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-02 20:04:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int add(int x = 1,int y = 0)
{
	return x + y;
}

int add(int x,int y,int z)
{
	return x + y + z +1;
}

int main()
{
	int a = 3 ,b = 4;
	cout << "a + b = " << add(a,b) << endl;
	cout << "a + b + c = " << add(a,b,0) << endl;
	cout << add(a) << endl;
	cout << add() << endl;
	return 0;
}
