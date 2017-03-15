 ///
 /// @file    deliver.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-07 17:29:24
 ///
 
#include "func.h"

void* thread(void* p)
{
	long i=(long)p;
	printf("main delivered %ld\n",i);
	i=5;
	return (void*)i;
}

int main()
{
	pthread_t pthid;
	long i=1;
	long ret;
	ret=pthread_create(&pthid,NULL,thread,(void*)i);
	if(0!=ret)
	{
		printf("pthread ret is %ld\n",ret);
		return -1;
	}
	pthread_join(pthid,(void**)&i);
	if(0!=ret)
	{
		printf("pthrea_join ret is %ld",ret);
		return -1;
	}
	printf("i=%ld\n",i);
	return 0;
}
 
