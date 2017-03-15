 //
 /// @file    nodefer.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-06 21:01:03
 ///
 
#include "func.h"

void sig(int signum,siginfo_t *p,void *p1)
{
	printf("before sleep,the sig %d is coming\n",signum);
	sleep(3);
	printf("after sleep,the sig %d is coming\n",signum);
}

int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction=sig;
	act.sa_flags=SA_SIGINFO|SA_NODEFER;
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
		perror("signation");
		return -1;
	}
	while(1);
	return 0;
}
 
