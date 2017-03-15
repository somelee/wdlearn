#include "head.h" 


//buf1为绝对路径，buf2为带有..的路径
//拼接结果为绝对路径
int path_dot(char* buf1,char* buf2)
{
	int i,j;
	if('.'==buf2[0] && '.'==buf2[1] && '/'==buf2[2])
	{
		for(i=0;i<100;i++)
		{
			if('\0'==buf1[i])
			{
				break;
			}
		}
		for(;i>0;i--)
		{
			if('/'==buf1[i])
			{
				break;
			}
			buf1[i]='\0';
		}
		for(j=2;j<100;j++)
		{
			if('\0'==buf2[j])
			{
				break;
			}
			buf1[i]=buf2[j];
			i++;
		}
	}else{
		printf("path error\n");
		return -1;
	}
	return 0;
}
