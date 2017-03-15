#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("error args.\n");
		return -1;
	}
	FILE *fp;
	fp=popen(argv[1],"w");
	if(NULL==fp)
	{
		perror("popen");
		return -1;
	}
	char buf[]="I am parent";
	printf("%s",buf);
	pclose(fp);
	return 0;
}
