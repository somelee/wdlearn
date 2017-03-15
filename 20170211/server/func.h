#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/uio.h>


//主进程保存的子进程信息
typedef struct childdata{
	pid_t pid;    //子进程pid
	int fdw;    //父子进程管道
	short busy;  //忙碌标记
}cdata,*pcdata;

//通讯协议
typedef struct tdata{
	int len;
	char buf[1000];
}td,*ptd;

int create_child(int,pcdata);
int child_main(int);
int net_init(int*,char*,char*);
int send_fd(int,int);
int recv_fd(int,int*);
int handle_request(int);
int send_n(int,char*,int);
int recv_n(int,char*,int);
