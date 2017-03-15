 ///
 /// @file    pthread.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-07 10:34:14
 ///
 
#include "func.h"

void* pthfunc(void* parg)
{
	printf("I am pthfunc\n");
	return NULL;
}

int main()
{
	pthread_t thdid;
	int ret;
	ret=pthread_create(&thdid,NULL,pthfunc,NULL);
	if(0!=ret)
	{
		printf("pthread is %d",ret);
		return -1;
	}
	printf("I am main\n");
	sleep(3);
	return 0;
}
 
