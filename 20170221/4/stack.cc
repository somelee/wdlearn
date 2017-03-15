 ///
 /// @file    stack.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-23 23:22:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size)
	:_top(-1)
	,_size(size)
	,_arr(new int[_size])
	{

	}

	~Stack()
	{
		if(NULL != _arr)
		{
			delete [] _arr;
			_arr = NULL;
		}
	}

	void push(int num)
	{
		if(!full())
		{
			_arr[++_top] = num; 
		}else{
			cout << "Stack full" << endl;
		}
	}

	void pop()
	{
		if(!empty())
		{
			--_top;
		}else{
			cout << "Stack empty" << endl;
		}
	}

	int top()
	{
		return _arr[_top];
	}

	bool empty()
	{
		return (-1 == _top);
	}
	bool full()
	{
		return ((_size - 1) == _top);
	}
private:
	int _top;
	int _size;
	int* _arr;
};

int main()
{
	Stack stack(10);
	cout << "当前的stack是否为空？" << stack.empty() << endl;

	stack.push(1);
	cout << "当前的stack是否为空？" << stack.empty() << endl;

	for(int idx = 2;idx <=10;++idx)
	{
		stack.push(idx);
	}
	cout << "当前的stack是否已满？" << stack.full() << endl;
	while(!stack.empty())
	{
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	
	return 0;
}
