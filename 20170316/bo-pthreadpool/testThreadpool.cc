 ///
 /// @file    testThreadpool.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-17 19:30:43
 ///
 
#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

class MyTask
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
	wd::Threadpool Threadpool(4,10);
	Threadpool.start();

	int cnt = 5;
	while(cnt--)
	{
		Threadpool.addTask(std::bind(&MyTask::execute,MyTask()));
		sleep(1);
	}

	Threadpool.stop();

	return 0;
}
