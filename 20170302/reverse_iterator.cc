 ///
 /// @file    reverse_iterator.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 20:42:38
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	vector<int> vecInt = {1,2,3,4,5};
	vector<int>::reverse_iterator rit;
	for(rit = vecInt.rbegin();rit != vecInt.rend();++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;

	return 0;
}
