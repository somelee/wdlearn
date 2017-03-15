#include "func.h"

int main()
{
	int ret;
	ret=fork();
	if(0==ret)
	{
		printf("I am children.\nI will quit and return 5\n");
		return 5;
	}else{
		sleep(2);
		int status;
		printf("I am parent.\nMy children`s pid=%d\n",ret);
		while(waitpid(ret,&status,WNOHANG),!WIFEXITED(status));
		printf("I recive return value.\n");
		printf("return=%d\n",WEXITSTATUS(status));
	}
}
