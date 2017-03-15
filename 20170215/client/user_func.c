#include "head.h"
#include "data.h"
#include "func.h"


int user_send(int nfd)
{
	nd ndata;
	memset(&ndata,0,sizeof(ndata));
	char user[100]={};
	char passwd[100]={};
	//发送用户名
	printf("login as:");
	scanf("%s",user);
	ndata.len=strlen(user);
	strcpy(ndata.buf,user);
	send_n(nfd,(char*)&ndata,8+ndata.len);
	//发送密码
	strcpy(passwd,getpass("passwd:"));
	ndata.len=strlen(passwd);
	strcpy(ndata.buf,passwd);
	send_n(nfd,(char*)&ndata,8+ndata.len);
}
 
