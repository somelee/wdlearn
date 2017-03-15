 ///
 /// @file    pending.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-06 17:34:07
 ///
 
#include "func.h"

void sig(int signum,siginfo_t *p,void *p1)
{
	printf("before sleep,the sig %d is coming\n",signum);
	sleep(3);
	sigset_t set;
	sigemptyset(&set);
	sigpending(&set);
	if(sigismember(&set,SIGQUIT))
	{
		printf("SIGQUIT is pending\n");
	}else{
		printf("SIGQUIT is not pending\n");
	}
	printf("after sleep,the sig %d is coming\n",signum);
}

int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction=sig;
	act.sa_flags=SA_SIGINFO|SA_NODEFER;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	int ret;
	ret=sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("aigaction");
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
 
