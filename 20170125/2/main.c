#include "func.h"

int main()
{
	int ret;
	ret=fork();
	if(0==ret)
	{
		printf("I am children.\nI will come corpse progress\n");
		exit(0);
	}else{
		printf("I am parent.\nMy children will come orpse progress.\n");
		while(1);
		return 0;
	}
}
