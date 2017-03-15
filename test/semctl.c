 ///
 /// @file    semctl.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-08 14:36:58
 ///
 
#include "func.h"

int main()
{
	int semid=semget(1234,2,IPC_CREAT|0600);
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
	ret=semctl(semid,1,SETVAL,1);
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
	
	struct sembuf sp1,sv1;
	memset(&sp1,0,sizeof(sp1));
	memset(&sv1,0,sizeof(sv1));
	sp1.sem_num=1;
	sp1.sem_op=-1;
	sp1.sem_flg=SEM_UNDO;
	sv1.sem_num=1;
	sv1.sem_op=1;
	sv1.sem_flg=SEM_UNDO;

	semop(semid,&sp,1);
	printf("semop\n");
	semop(semid,&sv,1);

	semop(semid,&sp1,1);
	printf("semop2\n");
	semop(semid,&sv1,1);

	semctl(semid,1,IPC_RMID,1);

	return 0;
}
 
