 ///
 /// @file    deliver_fd.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 11:18:26
 ///

//****************************************
//父子进程间传递文件描述符
//与以下函数配合使用
//int fds[2];
//socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
//*****************************************

#include "func.h"
//发送文件描述符，fdw为创建的管道fds[2]的写端，fd为发送的文件描述符
int send_fd(int fdw,int fd)
{
	struct msghdr msg;
	memset(&msg,0,sizeof(msg));
	char buf[10]="buf";
	char buf1[10]="buf1";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=3;
	iov[1].iov_base=buf1;
	iov[1].iov_len=4;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level=SOL_SOCKET;
	cmsg->cmsg_type=SCM_RIGHTS;
	*(int*)CMSG_DATA(cmsg)=fd;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=sendmsg(fdw,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return -1;
	}
	return 0;
}
//文件描述符的接收端，fdw为fds[2]的写端，fd为传出文件描述符
int recv_fd(int fdw,int* fd)
{
	struct msghdr msg;
	memset(&msg,0,sizeof(msg));
	char buf[10]="buf";
	char buf1[10]="buf1";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=3;
	iov[1].iov_base=buf1;
	iov[1].iov_len=4;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level=SOL_SOCKET;
	cmsg->cmsg_type=SCM_RIGHTS;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=recvmsg(fdw,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return -1;
	}
	*fd=*(int*)CMSG_DATA(cmsg);
	return 0;
}
