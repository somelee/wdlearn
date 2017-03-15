 ///
 /// @file    replace_if.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 16:59:08
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

bool func(int num)
{
	if(num > 3)
		return true;
	else
		return false;
}

int main()
{
	vector<int> vecInt = {1,2,3,4,5,6,7};

	std::less<int> it;

	replace_if(vecInt.begin(),vecInt.end(),bind1st(it,3),8);

	ostream_iterator<int> osi(cout," ");
	copy(vecInt.begin(),vecInt.end(),osi);
	cout << endl;

	return 0;
}
