#include "func.h"

typedef struct student
{
	int num;
	char name[20];
	float score;
} stu;

int main()
{
	stu s[3]={1001,"litongxue",100,1002,"changtongxue",100,1003,"zhangtongxue",99};
	int fd=open("list.txt",O_CREAT|O_RDWR|O_TRUNC,0664);
	//for(int i=0;i<3;i++)
	//{
	//	printf("%-10d%-17s%6.2f\n",s[i].num,s[i].name,s[i].score);
	//}
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	write(fd,s,sizeof(s));
	lseek(fd,0,SEEK_SET);
	//close(fd);
	//fd=open("list.txt",O_CREAT);
	stu s1[3]={0};
	read(fd,s1,sizeof(s1));
	for(int i=0;i<3;i++)
	{
		printf("%-10d%-17s%6.2f\n",s1[i].num,s1[i].name,s1[i].score);
	}
	close(fd);
	return 0;
}
