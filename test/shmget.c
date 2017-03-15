#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("error args.\n");
		return -1;
	}
	key_t key;
	printf("%s\n",argv[0]);
	key=ftok(argv[0],1);
	printf("key=%d\n",key);
	return 0;
}
