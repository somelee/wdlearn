 ///
 /// @file    priority_queue.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 19:46:39
 ///
 
#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

int main()
{
	int arr[10] = {0,1,3,2,5,6,9,8,7,4};
	priority_queue<int,vector<int>,std::greater<int>> priQueue;
	for(size_t idx = 0;idx != 10;++idx)
	{
		priQueue.push(arr[idx]);
		cout << "当时队列之中优先级最高的是：" << priQueue.top() << endl;
	}

	while(!priQueue.empty())
	{
		cout << priQueue.top() << " ";
		priQueue.pop();
	}
	cout << endl;

	return 0;
}
