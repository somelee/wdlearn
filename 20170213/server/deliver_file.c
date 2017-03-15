#include "normal.h"
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
