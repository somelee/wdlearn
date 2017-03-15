 ///
 /// @file    writev.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-11 10:22:13
 ///
 
#include "func.h"

int main()
{
	int fd;
	fd=open("file1",O_RDWR);
	char buf[10]="hello";
	char buf1[10]=" world";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=6;
	writev(fd,iov,2);
	close(fd);
	return 0;
}
