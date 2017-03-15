#include "func.h"

int main()
{
	int fds[2];
	pipe(fds);
	int ret;
	ret=fork();
	if(0==ret)
	{
		close(fds[1]);
		char buf[20]={0};
		int ret1;
		ret1=read(fds[0],buf,sizeof(buf));
		if(ret1<=0)
		{
			perror("read");
			return -1;
		}
		puts(buf);
		close(fds[0]);
		exit(0);
	}else{
		close(fds[0]);
		char s[]={"I am your parent."};
		write(fds[1],s,sizeof(s));
		wait(NULL);
		close(fds[1]);
		printf("pipe over.\n");
		return 0;
	}
}
