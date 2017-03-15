//********************************************
//本函数连接ip和端口号
//psfd为传出参数，传出该端口的文件描述符的编号
//*********************************************

#include "head.h"

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
	ret=connect(*psfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	return 0;
}
