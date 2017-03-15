 ///
 /// @file    send_fd.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-11 16:06:14
 ///
 
#include "func.h"

void send_fd(int fdw,int fd)
{
	struct msghdr msg;
	memset(&msg,0,sizeof(msg));
	char buf[10]="hello";
	char buf1[10]=" world";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=6;
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
		return;
	}
}

void recv_fd(int fdr,int* fd)
{
	struct msghdr msg;
	memset(&msg,0,sizeof(msg));
	char buf[10]="hello";
	char buf1[10]=" world";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=6;
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
	ret=recvmsg(fdr,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return;
	}
	*fd=*(int*)CMSG_DATA(cmsg);
}

int main()
{
	int fds[2];
	socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
	if(!fork())
	{
		close(fds[1]);
		int fd;
		recv_fd(fds[0],&fd);
		printf("fd=%d\n",fd);
		char buf[20]={};
		read(fd,buf,sizeof(buf));
		printf("buf=%s\n",buf);
		close(fds[0]);
		exit(0);
	}else{
		close(fds[0]);
		int fd;
		fd=open("file",O_RDWR);
		printf("parent fd=%d\n",fd);
		send_fd(fds[1],fd);
		wait(NULL);
		return 0;
	}
	return 0;
}
