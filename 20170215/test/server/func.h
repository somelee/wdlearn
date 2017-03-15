#ifndef __FUNC_H__
#define __FUNC_H__
#include "head.h"
#include "data.h"

#define child_count 20 

int send_n(int,char*,int);//网络接收文件
int recv_n(int,char*,int);//网络发送文件
int recv_nd(int,pnd);
int send_fd(int,int);//父子进程发送文件描述符
int recv_fd(int,int*);//父子进程接收文件描述符

int read_config(char*,char (*conf)[50]);//读取配置文件
int net_init(int*,char (*conf)[50]);//网络初始化

int path(char*,char*,char*);//path处理
int path_dot(char*,char*);//读取配置文件专用

int myls(int,char*,pnd);
int upload(int,char*);
int download(int,char*);

int handle_request(int);//响应请求
int create_child(pcd);//创建子进程
int child_main(int);//子进程主函数
#endif
