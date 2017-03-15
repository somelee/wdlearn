 ///
 /// @file    sequence1.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-02 17:12:37
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

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
//	double arr[5] = {1,2,3,4,5};
//	deque<double> doubleDeque(arr,arr + 5);
	deque<double> doubleDeque = {1,2,3,4,5};

//	for(size_t idx = 0;idx != doubleDeque.size();++idx)
//	{
//		cout << doubleDeque[idx] << " ";
//	}
//	cout << endl;
	printContainer(doubleDeque);

	deque<double>::iterator it;
	for(it = doubleDeque.begin();it != doubleDeque.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<float> listFloat(3,5);
	list<float>::iterator lit;
	for(lit = listFloat.begin();lit != listFloat.end();++lit)
	{
		cout << *lit << " ";
	}
	cout << endl;

	list<float> listFloat2(4,3);
	listFloat.swap(listFloat2);
	printContainer(listFloat);

	return 0;
}
