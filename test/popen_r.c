#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("error args");
		return -1;
	}
	FILE *fp;
	fp=popen(argv[1],"r");
	if(NULL==fp)
	{
		perror("popen");
		return -1;
	}
	char buf[30]={0};
	fgets(buf,sizeof(buf)-1,fp);
	printf("%s",buf);
	return 0;
}
