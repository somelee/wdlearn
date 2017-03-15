 ///
 /// @file    real.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-07 09:02:11
 ///
 
#include "func.h"

void sig(int signum)
{
	time_t t;
	time(&t);
	printf("%s\n",ctime(&t));
}

int main()
{
	signal(SIGPROF,sig);
	kill(0,SIGPROF);
	struct itimerval t;
	memset(&t,0,sizeof(t));
	t.it_value.tv_sec=3;
	t.it_interval.tv_sec=2;
	int ret;
	ret=setitimer(ITIMER_PROF,&t,NULL);
	if(-1==ret)
	{
		perror("setitimer");
		return -1;
	}
	pause();
	while(1);
}
 
