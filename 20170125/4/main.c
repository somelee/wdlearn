#include "func.h"

int main()
{
	int ret;
	ret=fork();
	if(ret)
	{
		exit(0);
	}
	setsid();
	chdir("/");
	while(1);//没打开文件，不关闭
	return 0;	
}
