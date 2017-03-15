#include "head.h"
#include "data.h"
#include "func.h"

long fd_total=1;
long fd_len=0;

void sigdownload(int signum)
{
	float n;
	n=((float)fd_len)/((float)fd_total);
	printf("download %5.2f%%\n",n*100);
}

void sigupload(int signum)
{
	float n;
	n=((float)fd_len)/((float)fd_total);
	printf("upload %5.2f%%\n",n*100);
}
//上传文件
int upload(int nfd,char* file)
{
	nd ndata;
	memset(&ndata,0,sizeof(ndata));
	ndata.cmd=3;
	//打开文件
	int fd;
	fd=open(file,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("file=%s\n",file);
	//发送文件名
	ndata.len=strlen(file);
	memcpy(ndata.buf,file,ndata.len);
	send_n(nfd,(char*)&ndata,8+ndata.len);
	//获取文件信息
	struct stat buf;
	memset(&buf,0,sizeof(buf));
	stat(file,&buf);
	ndata.len=sizeof(buf);
	memcpy(ndata.buf,&buf,sizeof(buf));
	send_n(nfd,(char*)&ndata,8+ndata.len);
	fd_total=buf.st_size;

	//核对文件大小
	recv_nd(nfd,&ndata);
	memcpy(&buf,ndata.buf,sizeof(buf));
	fd_len=buf.st_size;//文件大小
	lseek(fd,fd_len,SEEK_SET);
	//进度条
	signal(SIGALRM,sigupload);
	struct itimerval time;
	memset(&time,0,sizeof(time));
	time.it_value.tv_sec=1;
	time.it_interval.tv_sec=1;
	setitimer(ITIMER_REAL,&time,NULL);

	printf("upload begin\n");
	//发送文件
	while(memset(&ndata,0,sizeof(ndata)),(ndata.len=read(fd,ndata.buf,sizeof(ndata.buf)))>0)
	{
		fd_len=fd_len+ndata.len;
		send_n(nfd,(char*)&ndata,8+ndata.len);
	}
	ndata.len=0;
	send_n(nfd,(char*)&ndata,8);
	close(fd);
	//关闭进度条
	memset(&time,0,sizeof(time));
	time.it_value.tv_sec=0;
	time.it_interval.tv_sec=1;
	setitimer(ITIMER_REAL,&time,NULL);
	printf("upload %s complete\n",file);
	return 0;
}

int download(int nfd,char* file)
{
	nd ndata;
	memset(&ndata,0,sizeof(ndata));
	printf("file=%s\n",file);
	//新建文件
	int fd;
	fd=open(file,O_RDWR|O_CREAT|O_APPEND,0666);

	//接收文件大小
	struct stat buf;
	recv_nd(nfd,&ndata);
	memcpy(&buf,ndata.buf,sizeof(buf));
	fd_total=buf.st_size;//文件大小
	printf("size=%ld\n",fd_total);
	fd_len=1;

	//反馈已有文件大小
	memset(&buf,0,sizeof(buf));
	stat(file,&buf);
	ndata.len=sizeof(buf);
	memcpy(ndata.buf,&buf,sizeof(buf));
	send_n(nfd,(char*)&ndata,8+ndata.len);

	printf("%s download starting\n",file);
	//进度条
	signal(SIGALRM,sigdownload);
	struct itimerval time;
	memset(&time,0,sizeof(time));
	time.it_value.tv_sec=1;
	time.it_interval.tv_sec=1;
	setitimer(ITIMER_REAL,&time,NULL);

	while(1)
	{
		memset(&ndata,0,sizeof(ndata));
		recv_n(nfd,(char*)&ndata.len,4);
		if(ndata.len>0)
		{
			recv_n(nfd,(char*)&ndata.cmd,4);
			fd_len=fd_len+ndata.len;
			recv_n(nfd,ndata.buf,ndata.len);
			write(fd,ndata.buf,ndata.len);
		}else{
			//关闭进度条
			recv_n(nfd,(char*)&ndata.cmd,4);
			memset(&time,0,sizeof(time));
			time.it_value.tv_sec=0;
			time.it_interval.tv_sec=1;
			setitimer(ITIMER_REAL,&time,NULL);
			printf("download complete\n");
			break;
		}
	}
	close(fd);
	return 0;
}
