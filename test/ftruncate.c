#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("error args");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDWR|O_CREAT,0664);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	int ret;
	ret=ftruncate(fd,1<<20);
	if(-1==ret)
	{
		perror("ftrncate");
		return -1;
	}
	close(fd);
	return 0;
}
