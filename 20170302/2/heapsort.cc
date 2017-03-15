 ///
 /// @file    heapsort.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-04 15:06:20
 ///
 
#include <iostream>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::deque;

template <typename T>
class HeapSort
{
public:
	HeapSort(deque<T> & arr)
	:_arr(arr)
	{
		int size = _arr.size();
		if(0 == size)
		{
			cout << "data error." << endl;
			return;
		}
		if(1 == size)
		{
			return;
		}
		int i ;
		auto tmp = _arr[0];
		while(1)
		{
			i = size/2 - 1;
			while(1)
			{
				if(_arr[i] < _arr[2*i + 1])
				{
					tmp = _arr[i];
					_arr[i] = _arr[2*i + 1];
					_arr[2*i + 1] = tmp;
				}
				if((2*i + 2) < size)
				{
					if(_arr[i] < _arr[2*i +2])
					{
						tmp = _arr[i];
						_arr[i] = _arr[2*i + 2];
						_arr[2*i + 2] = tmp;
					}
				}
				if(0 == i)
				{
					break;
				}
				--i;
			}
			tmp = _arr[0];
			_arr[0] = _arr[size - 1];
			_arr[size - 1] = tmp;
			if(2 == size)
			{
				return;
			}
			--size;
		}
	}

	void display()
	{
		for(auto & elem : _arr)
		{
			cout << elem << " ";
		}
		cout << endl;
	}
private:
	deque<T> & _arr;
	int _i;
};

int main()
{
	deque<int> intSort;
	int i;
	while(cin >> i)
	{
		intSort.push_back(i);
	}

	cout << "Input :" << endl;
	for(auto & elem : intSort)
	{
		cout << elem << " ";
	}
	cout << endl;

	HeapSort<int> Sort(intSort);
	Sort.display();

	return 0;
}
