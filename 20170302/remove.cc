 ///
 /// @file    remove.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 18:35:40
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vecInt = {1,2,3,4,5,6,7,8,9,10};
	cout << "vecInt`s capacity = " << vecInt.capacity() << endl;

	vecInt[3] = vecInt[5] = vecInt[9] = 99;

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;

	vecInt.erase(remove(vecInt.begin(),vecInt.end(),99),vecInt.end());
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}
