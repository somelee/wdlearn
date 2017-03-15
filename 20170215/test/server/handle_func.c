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

int handle_request(int fd)
{
	nd ndata;
	memset(&ndata,0,sizeof(ndata));
	char pwdhome[]="/home/ubuntu/20170215/home/";
	char pwdwork[100]="/home/ubuntu/20170215/home/";
	char pwdplay[100]="/home/";
	char pwdtemp[100]={};
	chdir(pwdwork);
	int ret;
	while(1)
	{
		memset(&ndata,0,sizeof(ndata));
		memset(pwdtemp,0,sizeof(pwdtemp));
		recv_nd(fd,&ndata);
		printf("recv: len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
		switch(ndata.cmd)
		{
			case 1:memcpy(pwdtemp,pwdwork,sizeof(pwdtemp));
				   printf("path1\n");
				   ret=path(pwdtemp,ndata.buf,pwdhome);
				   if(-1==ret)
				   {
					   ndata.cmd=-1;
				   }
				   printf("chdir\n");
				   ret=chdir(pwdtemp);
				   printf("ret=%d\n",ret);
				   if(-1==ret)
				   {
					   ndata.cmd=-1;
				   }else{
					   memcpy(pwdwork,pwdtemp,sizeof(pwdtemp));
					   path(pwdplay,ndata.buf,pwdplay);
					   printf("path2\n");
				   }
				   ndata.len=strlen(pwdwork);
				   memcpy(ndata.buf,pwdwork,ndata.len);
				printf("send: len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   send_n(fd,(char*)&ndata,8+ndata.len);
				   printf("send_n\n");
				break;
			case 2:memset(&ndata,0,sizeof(ndata));
				   myls(fd,pwdwork,&ndata);
				   memset(&ndata,0,sizeof(ndata));
				   ndata.len=0;
				   ndata.cmd=2;
				   send_n(fd,(char*)&ndata,8);
				break;
			case 3:download(fd,ndata.buf);
				break;
			case 4:upload(fd,ndata.buf);
				break;
			case 5:memset(pwdtemp,0,sizeof(pwdtemp));
				   sprintf(pwdtemp,"%s/%s",pwdwork,ndata.buf);
				   printf("remove:%s\n",pwdtemp);
				   ret=remove(pwdtemp);
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
				break;
			case 6:ndata.len=strlen(pwdwork);
				   memcpy(ndata.buf,pwdwork,ndata.len);
				printf("send: len=%d,cmd=%d,buf=%s\n",ndata.len,ndata.cmd,ndata.buf);
				   send_n(fd,(char*)&ndata,8+ndata.len);
				break;
			default:
				break;
		}
	}
}

