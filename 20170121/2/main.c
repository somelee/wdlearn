#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	struct stat buf;
	DIR *dir;
	dir=opendir(argv[1]);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	off_t pos;
	while((p=readdir(dir))!=NULL)
	{
		memset(&buf,0,sizeof(buf));
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
		for(i=0;i<3;i++)
		{
			n11=buf.st_mode & n1;
			if(n11 == n1)
			{
				printf("r");
			}else{
				printf("-");
			}
			n22=buf.st_mode & n2;
			if(n22 == n2)
			{
				printf("w");
			}else{
				printf("-");
			}
			n33=buf.st_mode & n3;
			if(n33 == n3)
			{
				printf("x");
			}else{
				printf("-");
			}
			n1=n1>>3;
			n2=n2>>3;
			n3=n3>>3;
		}
		printf(" %d %7s %7s %ld %20s %10s\n",buf.st_nlink,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,buf.st_size,ctime(&buf.st_mtime),p->d_name);
	}
	return 0;
}
