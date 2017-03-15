 ///
 /// @file    insert_iterator.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 21:19:32
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;

template <typename Container>
void printElements(Container & c)
{
	typename Container::const_iterator cit;
	for(cit = c.begin();cit != c.end();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vecInt = {1,2,3};

	list<int> listInt;

	copy(vecInt.begin(),vecInt.end(),std::back_insert_iterator<list<int>>(listInt));

	printElements(listInt);
	
	copy(vecInt.begin(),vecInt.end(),std::front_insert_iterator<list<int>>(listInt));

	printElements(listInt);

	copy(vecInt.begin(),vecInt.end(),std::insert_iterator<list<int>>(listInt,listInt.begin()));

	printElements(listInt);

	return 0;
}
