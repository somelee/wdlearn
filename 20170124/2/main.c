#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("error args\n");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDWR|O_CREAT,0664);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	struct stat buf;
	stat(argv[1],&buf);
	int ret;
	char *p;
	p=(char*)mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if((char*)-1==p)
	{
		perror("mman");
		return -1;
	}
	printf("p[0]=%c\n",p[0]);
	p[0]='H';
	ret=munmap(p,buf.st_size);
	if(-1==ret)
	{
		perror("munmap");
		return -1;
	}
	close(fd);
	return 0;
}
