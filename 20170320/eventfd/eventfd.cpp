 ///
 /// @file    eventfd.cpp
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-28 23:53:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#include <sys/eventfd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define handle_error(msg) \
		do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc,char *argv[])
{
	int efd,j;
	uint64_t u;
	ssize_t s;

	if(argc < 2)
	{
		fprintf(stderr,"Usage: %s <num>...\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	efd = eventfd(10,0);
	if(efd == -1)
		handle_error("eventfd");

	switch (fork())
	{
		case 0:
			for (j = 1;j < argc;j++)
			{
				printf("Child writing %s to efd\n",argv[j]);
				u = strtoull(argv[j],NULL,0);
				s = write(efd,&u,sizeof(uint64_t));
				if(s != sizeof(uint64_t))
					handle_error("write");
				sleep(2);
			}
			printf("Child completed write loop\n");
			exit(EXIT_FAILURE);
		default:
			printf("Parent about to read\n");
			sleep(2);

			for(size_t idx = 0;idx < (argc - 1);++idx)
			{
				memset(&u,0,sizeof(u));
				s = read(efd,&u,sizeof(uint64_t));

				if(s != sizeof(uint64_t))
					handle_error("read");
				printf("Parent read %llu (0x%llx) from efd\n",(unsigned long long) u,(unsigned long long) u);
				sleep(2);
			}
			exit(EXIT_FAILURE);
		case -1:
			handle_error("fork");
	}

	return 0;
}
