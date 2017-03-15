 ///
 /// @file    sequence2.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-02 19:04:15
 ///
 
#include <iostream>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;

template <typename Container>
void printContainer(Container & c)
{
	typename Container::iterator cit;
	for(cit = c.begin();cit != c.end();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vecInt = {1,2,3,4,5};
	printContainer(vecInt);
	vecInt.pop_back();
	printContainer(vecInt);

	list<int> lisInt = {1,2,3,4,5};
	printContainer(lisInt);
	lisInt.push_front(9);
	printContainer(lisInt);

	vecInt.clear();
	cout << "vecInt`s size() = " << vecInt.size() << endl;
	cout << "vecInt`s capacity() = " << vecInt.capacity() << endl;
	vecInt.push_back(1);
	vecInt.shrink_to_fit();
	cout << "vecInt`s capacity() = " << vecInt.capacity() << endl;

	lisInt.clear();
	cout << "lisInt`s size() = " << lisInt.size() << endl;
	return 0;

}
