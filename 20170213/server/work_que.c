#include "work_que.h"

void que_init(pque p)
{
	memset(p,0,sizeof(que_t));
	pthread_mutex_init(&p->mutex,NULL);
}

void que_add(pque p,int new_fd)
{
	pNode pnew=(pNode)calloc(1,sizeof(Node));
	pnew->new_fd=new_fd;
	pthread_mutex_lock(&p->mutex);
	if(NULL==p->ptail)
	{
		p->phead=pnew;
		p->ptail=pnew;
	}else{
		p->ptail->pnext=pnew;
		p->ptail=pnew;
	}
	(p->size)++;
	pthread_mutex_unlock(&p->mutex);
}

void que_get(pque p,pNode* pn)
{
	*pn=p->phead;
	p->phead=p->phead->pnext;
	(p->size)--;
}
