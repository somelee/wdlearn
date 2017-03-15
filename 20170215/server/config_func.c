#include "head.h" 
#include "func.h"

int read_config(char* p,char (*conf)[50])
{
	int i,j,h=0;
	char buf[100]={};
	getcwd(buf,100);
	path_dot(buf,p);
	int fd=open(buf,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	read(fd,buf,sizeof(buf)-1);
	for(i=0;i<100;i++)
	{
		if('='==buf[i])
		{
			i=i+1;
			for(j=0;j<100;j++)
			{
				if('\n'==buf[i] || EOF==buf[i])
				{
					break;
				}
				conf[h][j]=buf[i];
				i++;
			}
			h=h+1;
		}
		if(2==h)
		{
			break;
		}
	}
	return 0;
}
