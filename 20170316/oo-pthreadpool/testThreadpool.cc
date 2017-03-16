 ///
 /// @file    testThreadpool.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-16 16:02:27
 ///
 
#include "Threadpool.h"
#include "Task.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

class MyTask
:public wd::Task
{
public:
	void execute()
	{
		srand(time(NULL));

		int number = rand() % 100;

		cout << "number = " << number << endl;
	}
};

int main()
{
	shared_ptr<wd::Task> sp(new MyTask);

	wd::Threadpool threadpool(4,10);
	threadpool.start();

	int cnt = 20;
	while(cnt--)
	{
		threadpool.addTask(sp.get());
		sleep(1);
	}

	threadpool.stop();

	return 0;
}
