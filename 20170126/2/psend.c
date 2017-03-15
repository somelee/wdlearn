#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("Please introduc only a args.\n");
		return -1;
	}
	key_t key;
	key=ftok(argv[1],1);
	int shmid;
	shmid=shmget(key,7,IPC_CREAT|0600);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	printf("shmget=%d\n",shmid);
	char *p;
	p=(char*)shmat(shmid,NULL,0);
	if((char*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	strcpy(p,"hello");
	system("ipcs");
	return 0;
}
