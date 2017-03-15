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

int user_init(pusr);//初始化用户
int read_config(char*,char (*conf)[50]);//读取配置文件
int net_init(int*,char*,char*);//网络初始化
int get_salt(char*,char*);//取盐值
int user_send(int);//发送账户和密码
int user_check(int,char*);//验证用户密码

int path(char*,char*,char*);//path处理
int path_dot(char*,char*);//读取配置文件专用

int myls(int,char*,pnd);
int upload(int,char*);
int download(int,char*);

int handle_request(int,pusr);//响应请求
int create_child(pcd,pusr);//创建子进程
int child_main(int,pusr);//子进程主函数
#endif
