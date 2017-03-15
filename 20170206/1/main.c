 ///
 /// @file    main.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-06 21:49:06
 ///
 
#include "func.h"

void sig(int signum)
{
	printf("before sleep,the sig =%d\n",signum);
	sleep(3);
	printf("after sleep,the sig =%d\n",signum);
}

int main()
{
	signal(SIGINT,sig);
	signal(SIGQUIT,sig);
	while(1);
	return 0;
}
