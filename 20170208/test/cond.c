 ///
 /// @file    cond.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-08 10:31:07
 ///
 
#include "func.h"

typedef struct {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} thd,*pthd;

void* pthread(void* p)
{
	pthd d=(pthd)p;
	printf("I am child func.I will wait\n");
	pthread_mutex_lock(&d->mutex);
	pthread_cond_wait(&d->cond,&d->mutex);
	pthread_mutex_unlock(&d->mutex);
	printf("I weakup\n");
	pthread_exit(NULL);
}

int main()
{
	thd d;
	pthread_mutex_init(&d.mutex,NULL);
	pthread_cond_init(&d.cond,NULL);
	pthread_t thid;
	pthread_create(&thid,NULL,pthread,&d);
	sleep(1);
	pthread_cond_signal(&d.cond);
	pthread_cond_destroy(&d.cond);
	pthread_join(thid,NULL);
	return 0;
}
 
