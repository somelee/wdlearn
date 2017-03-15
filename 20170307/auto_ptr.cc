 ///
 /// @file    auto_ptr.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 16:59:42
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;

int main()
{
	double * pd = new double(7.77);
	auto_ptr<double> apd(pd);
	cout << "*apd = " << *apd << endl;
	cout << "pd = " << pd << endl;
	cout << "apd.get() = " << apd.get() << endl;

	int * p1 = new int(1);
	auto_ptr<int> api(p1);
	cout << "*pi = " << *api << endl;
	auto_ptr<int> api2(api);

	cout << "*api2 = " << *api2 << endl;
	cout << "*api = " << *api << endl;
	cout << "-----" << endl;

	return 0;
}
