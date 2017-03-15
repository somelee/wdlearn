 ///
 /// @file    uniq_str.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 17:14:50
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(3));
	return upi;
}

int main()
{
	unique_ptr<double> upd(new double(8.88));
	cout << "*upd = " << *upd << endl;
	cout << "upd.get() = " << upd.get() << endl;

	unique_ptr<int> upi = getValue();
	cout << "*upi = " << *upi << endl;

	vector<unique_ptr<int>> vec;
	vec.push_back(std::move(upi));

	cout << "*upi = " << *upi << endl;

	cout << "---------" << endl;

	return 0;
	return 0;
}
