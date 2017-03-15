#ifndef __FACTORY_H__
#define __FACTORY_H_
#include "work_que.h"
#include "normal.h"

typedef void* (*pthfunc)(void*);

typedef struct factory{
	pthread_t *pth;//指向存储子线程pid数组
	int tnum;//存储子线程个数
	pthfunc entry;//子线程入口函数
	pthread_cond_t cond;//条件变量
	int capibility; //能力
	que_t que;  //队列指针
	int start;
}fac,*pfac;

int net_init(int*,char*,char*);
int send_file(int);
void factory_init(pfac);
void factory_start(pfac);
int send_n(int,char*,int);
int recv_n(int,char*,int);
#endif

