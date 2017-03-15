 ///
 /// @file    shared_ptr.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 17:37:58
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

int main()
{
	shared_ptr<int> spi(new int(3));
	cout << "spi`s use_count() = " << spi.use_count() << endl;
	cout << "*spi = " << *spi << endl;
	cout << "spi`s get() = " << spi.get() << endl;
	{
	shared_ptr<int> spi2(spi);
	cout << "*spi = " << *spi << endl;
	cout << "*spi2 = " << *spi2 << endl;
	cout << "spi`s use_count() = " << spi.use_count() << endl;
	cout << "spi2`s use_count() = " << spi2.use_count() << endl;
	cout << "spi2`2 get() = " << spi2.get() << endl;
	}
	cout << endl;
	cout << "spi`s use_count() = " << spi.use_count() << endl;

	return 0;
}
