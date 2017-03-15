#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__
#include "normal.h"
//队列结点
typedef struct list{
	int new_fd;
	struct list *pnext;
}Node,*pNode;

//队列结构体
typedef struct work_que{
	pNode phead,ptail;
	pthread_mutex_t mutex;
	int size;
}que_t,*pque;

void que_init(pque);
void que_add(pque,int);
void que_get(pque,pNode*);
#endif
