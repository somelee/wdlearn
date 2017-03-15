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
	int semid;
	semid=semget(1234,1,IPC_CREAT|0600);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	int ret;
	ret=semctl(semid,0,SETVAL,1);
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	struct sembuf sp,sv;
	memset(&sp,0,sizeof(sp));
	memset(&sv,0,sizeof(sv));
	sp.sem_num=0;
	sp.sem_op=-1;
	sp.sem_flg=SEM_UNDO;
	sv.sem_num=0;
	sv.sem_op=1;
	sv.sem_flg=SEM_UNDO;
	if(fork())
	{
		while(i)
		{
			semop(semid,&sp,1);
			(*p)++;
			semop(semid,&sv,1);
			i--;
		}
		wait(NULL);
		printf("%d\n",*p);
		ret=shmctl(shmid,IPC_RMID,NULL);
		if(-1==ret)
		{
			perror("shmctl");
			return -1;
		}
		ret=semctl(semid,0,IPC_RMID);
		if(-1==ret)
		{
			perror("semctl");
			return -1;
		}
		exit(0);
	}else{	
		while(i)
		{
			semop(semid,&sp,1);
			(*p)++;
			semop(semid,&sv,1);
			i--;
		}
		return 0;
	}
}
