 ///
 /// @file    main.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-06 22:01:57
 ///
 
#include "func.h"

void sig(int signum)
{
	printf("the sig is %d\n",signum);
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
		perror("sigprocmask");
		return -1;
	}
	sleep(5);
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
		perror("sigrocmask");
		return -1;
	}
	return 0;
}
 
