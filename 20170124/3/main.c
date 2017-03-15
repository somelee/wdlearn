#include "func.h"

int main()
{
	int ret;
	ret=fork();
	if(0==ret)
	{
		printf("I am children,pid=%-6d,ppid=%-6d\n",getpid(),getppid());
		printf("Fine,thank you.\n");
		return 0;
	}else{
		printf("I am parent  ,pid=%-6d,ppid=%-6d\n",getpid(),getppid());
		printf("How are you?\n");
		sleep(1);
		return 0;
	}
}
