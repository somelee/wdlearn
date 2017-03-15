 ///
 /// @file    main.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-13 23:04:15
 ///
 
#include "factory.h"

//子线程函数
void* threadfunc(void* p)
{
	pfac pf=(pfac)p;
	pque pq=&pf->que;
	pNode pn;
	while(1)
	{
		pthread_mutex_lock(&pq->mutex);
		if(0==pq->size)
		{
			pthread_cond_wait(&pf->cond,&pq->mutex);
		}
		que_get(pq,&pn);
		pthread_mutex_unlock(&pq->mutex);
		printf("connect success.\n");
		send_file(pn->new_fd);
		free(pn);
	}
}


int main(int argc,char* argv[])
{
	if(5!=argc)
	{
		printf("args error\n");
		return -1;
	}
	fac f;
	memset(&f,0,sizeof(f));
	f.tnum=atoi(argv[3]);
	f.capibility=atoi(argv[4]);
	f.entry=threadfunc;
	factory_init(&f);
	factory_start(&f);
	int sfd;
	net_init(&sfd,argv[1],argv[2]);
	listen(sfd,f.capibility);
	printf("server launch.\n");
	int new_fd;
	while(1)
	{
		new_fd=accept(sfd,NULL,NULL);
		que_add(&f.que,new_fd);
		pthread_cond_signal(&f.cond);
	}
	return 0;
}
