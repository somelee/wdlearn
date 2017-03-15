 ///
 /// @file    signal.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-05 20:38:30
 ///
 
#include "func.h" 

void sig1(int num)
{
	printf("I am SIGINT,the sig num=%d.Before sleep.\n",num);
	sleep(3);
	printf("I am SIGINT,the sig num=%d.After sleep.\n",num);
}

void sig2(int num)
{
	printf("I am SIGQUIT,the sig num=%d.Before sleep.\n",num);
	sleep(3);
	printf("I am SIGQUIT,the sig num=%d.After sleep.\n",num);
}

int main()
{
	if(SIG_ERR==signal(SIGINT,sig1))
	{
		perror("SIGINT");
		return -1;
	}
	if(SIG_ERR==signal(SIGQUIT,sig2))
	{
		perror("SIGINT");
	}
	while(1);
	return 0;
}
