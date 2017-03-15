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
//将命令后的字符剥离出来
int nbuf(char* buf,pnd pndata,int i,int k)
{
	int j;
	while(' '==buf[k])
	{
		k++;
	}
	for(j=0;j<i-k;j++)
	{
		pndata->buf[j]=buf[j+k];
	}
	pndata->len=i-k;
//	printf("len=%d,cmd=%d,buf=%s\n",pndata->len,pndata->cmd,pndata->buf);
}

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("args error\n");
		return -1;
	}
	//连接网络
	int sfd;
	net_init(&sfd,argv[1],argv[2]);

	//初始化通讯协议
	nd ndata;
	memset(&ndata,0,sizeof(ndata));

	system("clear");
	printf("Client launch\n");

	//验证用户
	user_send(sfd);
	recv_nd(sfd,&ndata);
	if(0==ndata.cmd)
	{
		printf("user or passwd error\n");
		return -1;
	}else{
		printf("connect success\n");
	}
	char buf[100]={};
	int i,j,k;
	while(1)
	{
		memset(&ndata,0,sizeof(ndata));
		//读输入，直到回车结束
		i=0;
		while(read(STDIN_FILENO,&buf[i],1))
		{
			if('\n'==buf[i])
			{
				break;
			}
			i++;
		}
		buf[i]='\0';
		//跳过开头的空格
		k=0;
		while(' '==buf[k])
		{
			k++;
		}
		//判断为哪条指令
		//cd
		if('c'==buf[k+0] && 'd'==buf[k+1] && ' '==buf[k+2])
		{
			ndata.cmd=1;
			nbuf(buf,&ndata,i,k+2);
			if('/'==ndata.buf[0])
			{
				printf("path error\n");
				continue;
			}
			send_n(sfd,(char*)&ndata,8+ndata.len);
//			printf("send_n\n");
			recv_nd(sfd,&ndata);
//			printf("%s\n",ndata.buf);
			continue;
		}
		//ls
		if('l'==buf[k+0] && 's'==buf[k+1] && ('\0'==buf[k+2] || ' '==buf[k+2]))
		{
			ndata.cmd=2;
			ndata.len=0;
			send_n(sfd,(char*)&ndata,8);
			while(1)
			{
				recv_nd(sfd,&ndata);
				if(0==ndata.len)
				{
					break;
				}
				printf("%s\n",ndata.buf);
				memset(&ndata,0,sizeof(ndata));
			}
			continue;
		}
		//puts
		if('p'==buf[k+0] && 'u'==buf[k+1] && 't'==buf[k+2] && 's'==buf[k+3] && ' '==buf[k+4])
		{
			ndata.cmd=3;
			nbuf(buf,&ndata,i,k+4);
			upload(sfd,ndata.buf);
			continue;
		}
		//gets
		if('g'==buf[k+0] && 'e'==buf[k+1] && 't'==buf[k+2] && 's'==buf[k+3] && ' '==buf[k+4])
		{
			ndata.cmd=4;
			nbuf(buf,&ndata,i,k+4);
			send_n(sfd,(char*)&ndata,8+ndata.len);
			recv_nd(sfd,&ndata);
			download(sfd,ndata.buf);
			continue;
		}
		//remove
		if('r'==buf[k+0] && 'm'==buf[k+1] && ' '==buf[k+2])
		{
			ndata.cmd=5;
			nbuf(buf,&ndata,i,k+2);
			send_n(sfd,(char*)&ndata,8+ndata.len);
			recv_nd(sfd,&ndata);
			if(0==ndata.cmd)
			{
				printf("remove error\n");
			}
			if(1==ndata.cmd)
			{
				printf("remove success\n");
			}
			continue;
		}
		//pwd
		if('p'==buf[k+0] && 'w'==buf[k+1] && 'd'==buf[k+2] && (' '==buf[k+3] || '\0'==buf[k+3]))
		{
			ndata.cmd=6;
			nbuf(buf,&ndata,i,k+3);
			send_n(sfd,(char*)&ndata,8+ndata.len);
			recv_nd(sfd,&ndata);
			printf("%s\n",ndata.buf);
			continue;
		}
		printf("input error\n");
	}
}
