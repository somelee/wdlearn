#include "head.h" 
#include "data.h"
#include "func.h"

int recv_nd(int fd,pnd pndata)
{
	recv_n(fd,(char*)&pndata->len,sizeof(int));
	recv_n(fd,(char*)&pndata->cmd,sizeof(int));
	recv_n(fd,pndata->buf,pndata->len);
	return 0;
}

int handle_request(int fd,pusr p)
{
	pusr puser=p;
	int ret;
	char user[100]={};
	nd ndata;
	memset(&ndata,0,sizeof(ndata));
	ret=user_check(fd,user);
//	printf("ret=%d\n",ret);
	if(-1==ret)
	{
		ndata.len=0;
		ndata.cmd=0;
		send_n(fd,(char*)&ndata,8);
		return -1;
	}else{
		while(strcmp(puser->name,user))
		{
			puser++;
		}
		ndata.len=0;
		ndata.cmd=1;
		send_n(fd,(char*)&ndata,8);
	}
//	printf("%s\n",puser->pwdwork);
	time_t t;
	time(&t);
	char log[100]={};
	strcpy(log,user);
	struct sockaddr_in sa;
	int len1=sizeof(sa);
	getpeername(fd,(struct sockaddr*)&sa,&len1);
	sprintf(log,"%s%s ip=%s port=%d\n",ctime(&t),user,inet_ntoa(sa.sin_addr),ntohs(sa.sin_port));
	char pwdhome[100];
	char pwdwork[100];
	strcpy(pwdhome,puser->pwdhome);
	strcpy(pwdwork,puser->pwdwork);
	char pwdplay[100]="/home/";
	char pwdtemp[100]={};
	char pwdlog[100]={};
	chdir(pwdwork);
	int lfd;//log文件
	sprintf(pwdlog,"%s%s",pwdhome,user);
	lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND,0666);
	write(lfd,log,strlen(log));
	close(lfd);
	while(1)
	{
		memset(&ndata,0,sizeof(ndata));
		memset(pwdtemp,0,sizeof(pwdtemp));
		recv_nd(fd,&ndata);
		time(&t);
		memset(log,0,sizeof(log));
		sprintf(log,"%srecv: len=%d,cmd=%d,buf=%s\n",ctime(&t),ndata.len,ndata.cmd,ndata.buf);
		lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
		write(lfd,&log,strlen(log));
		close(lfd);
		switch(ndata.cmd)
		{
			case 1:memcpy(pwdtemp,pwdwork,sizeof(pwdtemp));
				   ret=path(pwdtemp,ndata.buf,pwdhome);
				   if(-1==ret)
				   {
					   ndata.cmd=-1;
				   }
	//			   printf("chdir\n");
				   ret=chdir(pwdtemp);
	//			   printf("ret=%d\n",ret);
				   if(-1==ret)
				   {
					   ndata.cmd=-1;
				   }else{
					   memcpy(pwdwork,pwdtemp,sizeof(pwdtemp));
					   path(pwdplay,ndata.buf,pwdplay);
				   }
				   ndata.len=strlen(pwdplay);
				   memcpy(ndata.buf,pwdplay,ndata.len);
				   send_n(fd,(char*)&ndata,8+ndata.len);
				   memset(log,0,sizeof(log));
				   sprintf(log,"send:len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
				   write(lfd,&log,strlen(log));
				   close(lfd);
				break;
			case 2:memset(&ndata,0,sizeof(ndata));
				   myls(fd,pwdwork,&ndata);
				   memset(&ndata,0,sizeof(ndata));
				   ndata.len=0;
				   ndata.cmd=2;
				   send_n(fd,(char*)&ndata,8);
				   memset(log,0,sizeof(log));
				   sprintf(log,"send:len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
				   write(lfd,&log,strlen(log));
				   close(lfd);
				break;
			case 3:download(fd,ndata.buf);
				   memset(log,0,sizeof(log));
				   sprintf(log,"send:len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
				   write(lfd,&log,strlen(log));
				   close(lfd);
				break;
			case 4:upload(fd,ndata.buf);
				   memset(log,0,sizeof(log));
				   sprintf(log,"send:len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
				   write(lfd,&log,strlen(log));
				   close(lfd);
				break;
			case 5:memset(pwdtemp,0,sizeof(pwdtemp));
				   sprintf(pwdtemp,"%s/%s",pwdwork,ndata.buf);
				   ret=remove(pwdtemp);
				   memset(log,0,sizeof(log));
				   if(-1==ret)
				   {
					   ndata.len=0;
					   ndata.cmd=0;
					   send_n(fd,(char*)&ndata,8);
				   }else{
					   ndata.len=0;
					   ndata.cmd=1;
					   send_n(fd,(char*)&ndata,8);
				   }
				   sprintf(log,"send:len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
				   write(lfd,&log,strlen(log));
				   close(lfd);
				break;
			case 6:ndata.len=strlen(pwdplay);
				   memcpy(ndata.buf,pwdplay,ndata.len);
				   send_n(fd,(char*)&ndata,8+ndata.len);
				   memset(log,0,sizeof(log));
				   sprintf(log,"send:len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   lfd=open(pwdlog,O_RDWR|O_CREAT|O_APPEND);
				   write(lfd,&log,strlen(log));
				   close(lfd);
				break;
			default:
				break;
		}
	}
}

