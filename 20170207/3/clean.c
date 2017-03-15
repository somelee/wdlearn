 ///
 /// @file    clean.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-07 19:30:45
 ///
 
#include "func.h"

void clean(void* p)
{
	free(p);
	printf("I am clean func\n");
}

void* pthread(void* p)
{
	int* q=(int*)malloc(sizeof(int));
	pthread_cleanup_push(clean,q);
	printf("I am pthread func.\n");
	sleep(3);
	printf("I do not display\n");
	return NULL;
	pthread_cleanup_pop(1);
}
 
int main()
{
	pthread_t pthid;
	int ret;
	ret=pthread_create(&pthid,NULL,pthread,NULL);
	if(0!=ret)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	sleep(1);
	ret=pthread_cancel(pthid);
	if(0!=ret)
	{
		printf("pthread_cancel ret=%d\n",ret);
		return -1;
	}
	sleep(1);
	return 0;
}
