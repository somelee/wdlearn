#include "head.h"
#include "data.h"
#include "func.h"

int myls(int fd,char* pwdwork,pnd pndata)
{
	struct stat buf;
	DIR *dir;
	dir=opendir(pwdwork);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	off_t pos;
	int k;
	char buf1[100]={};
	while((p=readdir(dir))!=NULL)
	{
		memset(pndata,0,sizeof(nd));
		pndata->cmd=2;
		memset(&buf,0,sizeof(buf));
		memset(&buf1,0,sizeof(buf1));
		int ret;
		ret=stat(p->d_name,&buf);
		if(-1==ret)
		{
			perror("stat");
			return -1;
		}
		int d;
		d=buf.st_mode & 0040000;
		if(d == 0x0040000)
		{
			printf("d");
		}else{
			printf("-");
		}
		int i;
		int n1=00400,n11;
		int n2=00200,n22;
		int n3=00100,n33;
		k=0;
		for(i=0;i<3;i++)
		{
			n11=buf.st_mode & n1;
			if(n11 == n1)
			{
//				printf("r");
				buf1[k]='r';
				k++;
			}else{
//				printf("-");
				buf1[k]='-';
				k++;
			}
			n22=buf.st_mode & n2;
			if(n22 == n2)
			{
//				printf("w");
				buf1[k]='w';
				k++;
			}else{
//				printf("-");
				buf1[k]='-';
				k++;
			}
			n33=buf.st_mode & n3;
			if(n33 == n3)
			{
//				printf("x");
				buf1[k]='x';
				k++;
			}else{
//				printf("-");
				buf1[k]='-';
				k++;
			}
			n1=n1>>3;
			n2=n2>>3;
			n3=n3>>3;
		}
//		printf(" %ld %ld %20s %10s\n",buf.st_nlink,buf.st_size,ctime(&buf.st_mtime),p->d_name);
		pndata->len=sprintf(pndata->buf,"%s %ld %ld %20s %10s",buf1,buf.st_nlink,buf.st_size,ctime(&buf.st_mtime),p->d_name);
//		printf("%s\n",pndata->buf);
		send_n(fd,(char*)pndata,8+pndata->len);
	}
	return 0;
}
