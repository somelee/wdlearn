 ///
 /// @file    handle_request.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 10:12:34
 ///

#include "func.h"

int handle_request(int new_fd)
{
	td t;
	memset(&t,0,sizeof(t));
	recv_n(new_fd,(char*)&t.len,sizeof(int));//接收文件名
	recv_n(new_fd,(char*)t.buf,t.len);
	char name[1000]={};
	memcpy(name,t.buf,sizeof(name));
	printf("send:%s\n",name);
	int fd;
	fd=open(t.buf,O_RDONLY);//打开该文件
	if(-1==fd)//打开失败，发送错误信息
	{
		perror("open");
		send_n(new_fd,(char*)&fd,sizeof(int));
		return -1;
	}
	struct stat buf;
	stat(t.buf,&buf);
	t.len=sizeof(buf);
	memcpy(t.buf,&buf,sizeof(buf));
	send_n(new_fd,(char*)&t,t.len+sizeof(int));
	while(memset(&t,0,sizeof(t)),(t.len=read(fd,t.buf,sizeof(t.buf)))>0)
	{
		send_n(new_fd,(char*)&t,t.len+sizeof(int));
	}
	t.len=0;
	send_n(new_fd,(char*)&t.len,sizeof(int));
	close(new_fd);
	printf("%s complete\n",name);
	return 0;
}

