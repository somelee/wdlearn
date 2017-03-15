 ///
 /// @file    mem_fn.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-04 00:10:02
 ///
 
#include <iostream>
#include <functional>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class NumVal
{
public:
	NumVal()
	:_ix(0)
	{
	}

	NumVal(int ix)
	:_ix(ix)
	{
	}

	void display()
	{
		cout << _ix << " ";
	}

	bool isEven()
	{
		return (bool)!(_ix % 2);
	}

	bool isPrime()
	{
		for(int idx = 2;idx <= _ix / 2;++idx)
		{
			if(!(_ix % idx))
				return false;
		}
		return true;
	}
private:
	int _ix;
};

int main()
{
	vector<NumVal> vecArr(13);
	for(int idx = 0;idx != 13;++idx)
	{
		vecArr[idx] = NumVal(idx + 1);
	}

	for_each(vecArr.begin(),vecArr.end(),std::mem_fn(&NumVal::display));
	cout << endl;


	return 0;
}
