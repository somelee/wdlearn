 ///
 /// @file    main.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-06 22:01:57
 ///
 
#include "func.h"

void sig(int signum,siginfo_t *p,void *p1)
{
	printf("the sig is %d\n",signum);
	sleep(3);
	sigset_t set;
	sigemptyset(&set);
	sigpending(&set);
	if(sigismember(&set,SIGQUIT))
	{
		printf("\nSIGQUIT is pending\n");
	}else{
		printf("\nSIGQUIT is not pending\n");
	}
}

int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction=sig;
	act.sa_flags=SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	int ret;
	ret=sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}
	ret=sigaction(SIGQUIT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}
	while(1);
	return 0;
}
 
