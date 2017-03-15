 ///
 /// @file    dwliver_file.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 13:21:40
 ///
 
//*********************************
//此函数实现数据在网络中的完整发送
//**********************************

#include "func.h"
//发送数据
int send_n(int fd,char* buf,int len)
{
	int pos,total=0;
	while(total<len)
	{
		pos=send(fd,buf+total,len-total,0);
		total=total+pos;
	}
	return 0;
}

//接收数据
int recv_n(int fd,char* buf,int len)
{
	int pos,total=0;
	while(total<len)
	{
		pos=recv(fd,buf+total,len-total,0);
		total=total+pos;
	}
	return 0;
}
