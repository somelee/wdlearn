#include "func.h"

int main()
{
	int shmid;
	shmid=shmget(1234,sizeof(int),IPC_CREAT|0600);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	if((int*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	(*p)=0;
	int i=10000000;
	if(fork())
	{
		//usleep(1);
		while(i)
		{
			(*p)++;
			i--;
		}
		wait(NULL);
		printf("%d\n",*p);
		int ret;
		ret=shmctl(shmid,IPC_RMID,NULL);
		if(-1==ret)
		{
			perror("shmctl");
			return -1;
		}
		exit(0);
	}else{	
		while(i)
		{
			(*p)++;
			i--;
		}
		return 0;
	}
}
