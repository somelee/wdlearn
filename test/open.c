#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int lfd;
	lfd=open("hello",O_RDWR|O_CREAT|O_APPEND,0666);
	write(lfd,"hello1",strlen("hello1"));
	close(lfd);
	close(1);
}
