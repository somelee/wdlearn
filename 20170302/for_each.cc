 ///
 /// @file    for_each.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 16:10:12
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void print(int num)
{
	cout << num << " ";
}

int main()
{
	vector<int> vecInt = {1,2,3,4,5,6};
	for_each(vecInt.begin(),vecInt.end(),print);
	cout << endl;

	return 0;
}
