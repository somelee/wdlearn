 ///
 /// @file    ostream_iterator.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 15:21:54
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main()
{
	vector<int> vecInt = {1,2,3,4,5,6};

	ostream_iterator<int> osi(cout,"\n");
	std::copy(vecInt.begin(),vecInt.end(),osi);

	return 0;
}
