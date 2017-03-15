#include "func.h"

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("args error\n");
		return -1;
	}
	int fdr=open(argv[1],O_RDONLY);
	if(-1==fdr)
	{
		perror(argv[1]);
		return -1;
	}
	int fdw=open(argv[2],O_WRONLY);
	if(-1==fdw)
	{
		perror(argv[2]);
		return -1;
	}
	char buf[20]={0};
	printf("char2 open pipe success\n");
	fd_set rdset;
	int ret;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(fdr,&rdset))
			{
				memset(buf,0,sizeof(buf));
				if(read(fdr,buf,sizeof(buf)-1)>0)
				{
					printf("From chat1:%s\n",buf);
				}else{
					break;
				}
			}
			if(FD_ISSET(STDIN_FILENO,&rdset))
			{
				memset(buf,0,sizeof(buf));
				if(read(STDIN_FILENO,buf,sizeof(buf)-1)>0)
				{
					write(fdw,buf,strlen(buf)-1);
				}else{
					break;
				}
			}
		}
	}
	close(fdr);
	return 0;
}
