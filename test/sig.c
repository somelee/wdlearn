#include "func.h" 

int fd_total=1;
int fd_len=0;

void sig(int signum)
{
	float n;
	n=((float)fd_len)/((float)fd_total);
	printf("download %5.2f%%\n",n*100);
	fd_len++;
}
int main()
{
	signal(SIGALRM,sig);
	struct itimerval time;
	memset(&time,0,sizeof(time));
	time.it_value.tv_sec=1;
	time.it_interval.tv_sec=1;
	setitimer(ITIMER_REAL,&time,NULL);
	fd_total=100;
	fd_len=0;
	while(1);
	return 0;
}
