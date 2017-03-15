#include "head.h" 
#include "data.h"
#include "func.h"

int child_main(int fdr,pusr p)
{
	int new_fd;
	short flag=1;
	while(1)
	{
		recv_fd(fdr,&new_fd);
		printf("connect success\n");
		handle_request(new_fd,p);
		write(fdr,&flag,sizeof(flag));
	}
	return 0;
}

int create_child(pcd p,pusr pu)
{
	int i;
	int fds[2];
	pid_t pid;
	for(i=0;i<child_count;i++)
	{
		socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		pid=fork();
		if(!pid)
		{
			close(fds[1]);
			child_main(fds[0],pu);
		}
		close(fds[0]);
		p[i].pid=pid;
		p[i].fdw=fds[1];
		p[i].busy=0;
	}
	return 0;
}
