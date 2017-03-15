#ifndef __DATA_H__
#define __DATA_H__
#include "head.h"

//子进程信息表
typedef struct childdata{
	pid_t pid;//子进程pid
	int fdw; //管道的父进程端
	short busy;//忙碌标志位
}cd,*pcd;

//网络通信协议
typedef struct netdata{
	int len; //buf长度
	int cmd; //执行命令
	char buf[100];//内容
}nd,*pnd;
//len为buf的长度
//cmd为发送的指令控制信息
//buf存储内容
//cmd=-1，buf中为错误信息
//cmd=0，buf中为文件内容
//cmd=1，为cd指令，buf为路径
//cmd=2，为ls指令，buf为空
//cmd=3，为puts指令，buf为文件
//cmd=4，为gets指令，buf为文件名
//cmd=5，为remove指令，buf为文件名
//cmd=6，为pwd指令，buf为路径名
#endif
