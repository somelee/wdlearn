 ///
 /// @file    sigrocmask.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-06 19:49:24
 ///
 
#include "func.h"

void sig(int signum)
{
	printf("sig %d is coming\n",signum);
}

int main()
{
	signal(SIGINT,sig);
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	int ret;
	ret=sigprocmask(SIG_BLOCK,&set,NULL);
	if(-1==ret)
	{
		perror("sifprocmask");
		return -1;
	}
	sleep(10);
	sigset_t pset;
	sigemptyset(&pset);
	sigpending(&pset);
	if(sigismember(&pset,SIGINT))
	{
		printf("SIGINT is pending\n");
	}else{
		printf("SIGINT is not pending\n");
	}
	ret=sigprocmask(SIG_UNBLOCK,&set,NULL);
	if(-1==ret)
	{
		perror("sigprocmask");
		return -1;
	}
	return 0;
}
 
