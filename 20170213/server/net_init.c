 ///
 /// @file    net_init.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 10:39:10
 ///

//********************************************
//本函数绑定本机ip和端口号，不包含监听
//psfd为传出参数，传出该端口的文件描述符的编号
//*********************************************

#include "normal.h"

int net_init(int* psfd,char* ip,char* port)
{
	*psfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==*psfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(port));
	ser.sin_addr.s_addr=inet_addr(ip);
	int ret;
	ret=bind(*psfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	return 0;
}
