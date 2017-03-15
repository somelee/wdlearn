 ///
 /// @file    main.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-12 09:47:10
 ///
 
#include "func.h"

long fd_total=1;
long fd_len=0;

void sig(int signum)
{
	float n;
	n=((float)fd_len)/((float)fd_total);
	printf("Download %5.2f%%\n",n*100);
}

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("argv error\n");
		return -1;
	}

	int sfd;//连接服务器
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(ser));//连接服务器
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}

	td t;//通讯协议
	memset(&t,0,sizeof(t));
	printf("Welcome to use the download system.\n");//初始化界面
	printf("Please input file:\n");
	read(STDIN_FILENO,t.buf,sizeof(t.buf));//用户输入要下载的文件
	t.len=strlen(t.buf)-1;
	t.buf[t.len]=0;
	send_n(sfd,(char*)&t,t.len+sizeof(int));//客户端请求下载文件
	int fd;
	fd=open(t.buf,O_RDWR|O_CREAT,0666);//创建该文件,
	if(-1==fd)
	{
		printf("file already exit.\n");
		return -1;
	}else{	
		printf("%s download starting.\n",t.buf);
	}

	int flag=1;
	struct stat buf;//接收文件信息
	recv_n(sfd,(char*)&t.len,sizeof(int));
	if(-1==t.len)
	{
		printf("No such file or directory.\n");
		flag=0;
	}
	recv_n(sfd,t.buf,t.len);
	memcpy(&buf,t.buf,sizeof(buf));
	fd_total=buf.st_size;//文件大小

	if(flag)//如果可以接收文件则设置进度条
	{
		signal(SIGALRM,sig);//进度条设置
		struct itimerval time;
		memset(&time,0,sizeof(time));
		time.it_value.tv_sec=1;//每1s输出一次进度
		time.it_interval.tv_sec=1;
		setitimer(ITIMER_REAL,&time,NULL);
	}

	while(flag)
	{
		memset(&t,0,sizeof(t));
		recv_n(sfd,(char*)&t.len,sizeof(int));
		if(t.len>0)
		{
			fd_len=fd_len+t.len;
			recv_n(sfd,t.buf,t.len);
			write(fd,t.buf,t.len);
		}else{
			printf("download complete.\n");
			break;
		}
	}
	close(fd);
	close(sfd);
	return 0;
}
