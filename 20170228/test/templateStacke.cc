 ///
 /// @file    templateStacke.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-01 18:56:57
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T,int size = 10>
class Stack
{
public:
	Stack();

	bool empty();
	bool full();
	void push(const T &);
	void pop();
	const T & top() const;
private:
	int _top;
	T _arr[size];
};

template <typename T,int size>
Stack<T,size>::Stack()
:_top(-1)
{
	cout << "size = " << size << endl;
}

template <typename T,int size>
bool Stack<T,size>::empty()
{
	return -1 == _top;
}

template <typename T,int size>
bool Stack<T,size>::full()
{
	return size - 1 == _top;
}

template <typename T,int size>
void Stack<T,size>::push(const T & elem)
{
	if(!full())
	{
		_arr[++_top] = elem;
	}else{
		cout << "栈已满" << endl;
	}
}

template <typename T,int size>
void Stack<T,size>::pop()
{
	if(!empty())
	{
		--_top;
	}else{
		cout << "栈已空" << endl;
	}
}

template <typename T,int size>
const T & Stack<T,size>::top() const
{
	return _arr[_top];
}

int main()
{
	Stack<string,20> stackStr;
	cout << "此时栈是否为空？" << stackStr.empty() << endl;
	stackStr.push("aa");
	cout << "此时栈是否为空？" << stackStr.empty() << endl;
}
