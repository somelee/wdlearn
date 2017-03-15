#ifndef __FUNC_H__
#define __FUNC_H__
#include "head.h"
#include "data.h"

#define child_count 20 

int send_n(int,char*,int);//网络接收文件
int recv_n(int,char*,int);//网络发送文件
int recv_nd(int,pnd);

int upload(int,char*);
int download(int,char*);

int net_init(int*,char*,char*);//网络初始化

int path(char*,char*,char*);//path处理
int path_dot(char*,char*);
#endif
