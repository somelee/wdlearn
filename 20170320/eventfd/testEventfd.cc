 ///
 /// @file    testEventfd.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 23:44:16
 ///
 
#include "EventfdThread.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;

class Producer
{
public:
	void make()
	{
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "> number = " << number << endl;
	}
};

int main(void)
{
	wd::EventfdThread event(bind(&Producer::make,Producer()));
	event.start();
	int cnt = 20;
	while(cnt--)
	{
		::sleep(1);
		event.wakeup();
	}
	event.stop();
	return 0;
}
