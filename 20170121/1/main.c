#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>


int find(char* path,char* name)
{
	DIR* dir;
	dir=opendir(path);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	char buf[200]={0};
	while((p=readdir(dir))!=NULL)
	{
		if(!strcmp(p->d_name,name))
		{
			printf("path=%s\n",getcwd(NULL,0));
			return 0;
		}
		if(!strcmp(p->d_name,".")||!strcmp(p->d_name,".."))
		{
		}else{
			if(p->d_type==4)
			{
				sprintf(buf,"%s%s%s",path,"/",p->d_name);
				find(buf,name);
			}
		}
	}
}
int main(int argc,char* argv[])
{
	if(argc<2)
	{
		printf("error args\n");
		return -1;
	}
	find(argv[1],argv[2]);
	return 0;
}
