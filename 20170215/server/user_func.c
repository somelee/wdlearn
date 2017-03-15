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
	printf("passwd:");
	scanf("%s",passwd);
	ndata.len=strlen(passwd);
	strcpy(ndata.buf,passwd);
	send_n(nfd,(char*)&ndata,8+ndata.len);
}

//取盐值
int get_salt(char* salt,char* passwd)
{
	int i,j;
	//取出salt，i记录密码字符下标，j记录$出现的次数
	for(i=0,j=0;passwd[i] && j!=3;++i)
	{
		if('$'==passwd[i])
			++j;
	}
	strncpy(salt,passwd,i-1);
}

//验证客户端发来的密码
int user_check(int nfd,char* user)
{
	struct spwd *sp;
	char salt[512]={};
	char passwd[100]={};
	nd ndata;
	recv_nd(nfd,&ndata);
	strcpy(user,ndata.buf);
	recv_nd(nfd,&ndata);
	strcpy(passwd,ndata.buf);
	if((sp=getspnam(user))==NULL)//根据用户名取账户信息
	{
		perror("user");
		return -1;
	}
	get_salt(salt,sp->sp_pwdp);//取盐值
	//密码验证
	if(0!=strcmp(sp->sp_pwdp,crypt(passwd,salt)))//crypt把发来的密码和盐值一起加密，再对比加密后的字符
	{
		printf("passwd error\n");
		return -1;
	}
	return 0;
}

//在此将用户的信息存入程序
int user_init(pusr p)
{
	p->num=user_count;
	p->uid=1000;
	strcpy(p->name,"ubuntu");
	strcpy(p->pwdhome,"/home/ubuntu/home/");
	strcpy(p->pwdwork,p->pwdhome);
	p++;
	p->num=user_count;
	p->uid=1001;
	strcpy(p->name,"test1");
	strcpy(p->pwdhome,"/home/test1/home/");
	strcpy(p->pwdwork,p->pwdhome);
}
 
