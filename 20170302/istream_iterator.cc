 ///
 /// @file    istream_iterator.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 15:38:57
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::copy;

int main()
{
	vector<int> vecInt;
	cout << "vecInt`s capacity = " << vecInt.capacity() << endl;

	istream_iterator<int> isi(cin);
	copy(isi,istream_iterator<int>(),back_inserter(vecInt));
	cout << "vecInt`s capacity = " << vecInt.capacity() << endl;

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;


	return 0;
}
