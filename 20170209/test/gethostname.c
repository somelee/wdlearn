 ///
 /// @file    gethostname.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-09 18:56:38
 ///
 
#include "func.h"

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("argvs error\n");
		return -1;
	}
	struct hostent* hp;
	hp=gethostbyname(argv[1]);
	if(NULL==hp)
	{
		printf("gethostname h_errno is %d\n",h_errno);
		return -1;
	}
	printf("h_name=%s\n",hp->h_name);
	char** p2;
	p2=hp->h_aliases;
	for(;*p2!=NULL;p2++)
	{
		printf("h_aliases=%s\n",*p2);
	}
	printf("h_length=%d\n",hp->h_length);
	char ip[16]={};
	p2=hp->h_addr_list;
	const char *ret;
	for(int i=0;p2[i]!=NULL;i++)
	{
		memset(ip,0,sizeof(ip));
		ret=inet_ntop(hp->h_addrtype,p2[i],ip,sizeof(ip));
		printf("ip=%s\n",ip);
	}
	return 0;
}
