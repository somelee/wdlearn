 ///
 /// @file    pthread_100.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-07 15:51:58
 ///
 
#include "func.h"
#define N 10000000
pthread_mutex_t mutex;

void* thread(void* q)
{
	int *p=(int*)q;
	for(int i=0;i<N;i++)
	{
		pthread_mutex_lock(&mutex);
		++(*p);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t pthid;
	int ret;
	int *p=(int*)malloc(sizeof(int));
	*p=0;
	ret=pthread_mutex_init(&mutex,NULL);
	if(0!=ret)
	{
		printf("pthread_mutex_init ret=%d\n",ret);
		return -1;
	}
	ret=pthread_create(&pthid,NULL,thread,p);
	if(0!=ret)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	for(int i=0;i<N;i++)
	{
		pthread_mutex_lock(&mutex);
		++(*p);
		pthread_mutex_unlock(&mutex);
	}
	pthread_join(pthid,NULL);
	printf("*p=%d\n",*p);
	return 0;
}
 
