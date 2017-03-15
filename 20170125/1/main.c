#include "func.h"

int main()
{
	int ret;
	ret=fork();
	if(0==ret)
	{
		printf("I am children.\nI will come orphan.\n");
		while(1);
		return 1;
	}else{
		printf("I am parent.\nI will leave.\n");
		sleep(2);
		return 0;
	}
}
