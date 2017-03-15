 ///
 /// @file    heap.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-24 10:39:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int size)
	:_front(0)
	,_rear(0)
	,_size(size)
	,_arr(new int[size])
	{
	}
	~Queue()
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
			_arr[_rear] = num;
			_rear =( _rear + 1) % _size;
		}else{
			cout << "Queue full" << endl;
		}
	}
	void pop()
	{
		if(!empty())
		{
			_front =(_front + 1) % _size;
		}else{
			cout << "Queue empty" << endl; 
		}
	}
	int front()
	{
		return _arr[_front];
	}
	int back()
	{
		return _arr[(_rear -1 + _size) % _size];
	}
	bool empty()
	{
		return _front == _rear;
	}
	bool full()
	{
		return (_rear + 1) % _size == _front;
	}
private:
	int _front;
	int _rear;
	int _size;
	int* _arr;
};

int main()
{
	Queue queue(10);
	cout << "队列中是否为空？" << queue.empty() << endl;

	queue.push(1);
	cout << "队列中是否为空？" << queue.empty() << endl;

	for(int idx = 2;idx <= 10;++idx)
	{
		queue.push(idx);
	}
	cout << "队列里是否已满？" << queue.full() << endl;

	cout << "队尾元素是：" << queue.back() << endl;

	queue.pop();
	cout << "对头元素出队，再添加一个元素" << endl;
	queue.push(10);
	cout << "队尾元素是：" << queue.back() << endl << endl;

	while(!queue.empty())
	{
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;

	return 0;
}
