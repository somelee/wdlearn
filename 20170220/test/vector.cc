 ///
 /// @file    vector.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-23 21:27:03
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printCapacity(vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capacity = " << vec.capacity() << endl;
}

int main()
{
	vector<int> vecInt;
	vecInt.reserve(5);

	printCapacity(vecInt);
	cout << endl;

	vecInt.push_back(1);
	printCapacity(vecInt);
	vecInt.push_back(2);
	printCapacity(vecInt);
	vecInt.push_back(3);
	printCapacity(vecInt);
	vecInt.push_back(4);
	printCapacity(vecInt);
	vecInt.push_back(5);
	printCapacity(vecInt);
	vecInt.push_back(6);
	printCapacity(vecInt);
	vecInt.push_back(7);
	printCapacity(vecInt);
	vecInt.push_back(8);
	printCapacity(vecInt);
	vecInt.push_back(9);
	printCapacity(vecInt);
	vecInt.push_back(10);
	printCapacity(vecInt);
	vecInt.push_back(11);
	printCapacity(vecInt);
	vecInt.push_back(12);
	printCapacity(vecInt);
	vecInt.push_back(13);
	printCapacity(vecInt);
	vecInt.push_back(14);
	printCapacity(vecInt);

	for(size_t idx = 0;idx != vecInt.size();++idx)
	{
		cout << vecInt[idx] << " ";
	}
	cout << endl;

	vector<int>::iterator it;
	for(it = vecInt.begin();it != vecInt.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}
