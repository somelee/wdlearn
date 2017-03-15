 ///
 /// @file    inet_aton.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-09 15:30:24
 ///
 
#include "func.h"

int main(int argc,char* argv[])
{
	if(2!=argc)
	{
		printf("error args\n");
		return -1;
	}
	struct in_addr addr;
	memset(&addr,0,sizeof(addr));
	int ret;
	ret=inet_aton(argv[1],&addr);
	if(0==ret)
	{
		perror("inet_aton");
		return -1;
	}
	printf("addr=%x\n",addr.s_addr);
	printf("ip=%s\n",inet_ntoa(addr));
	unsigned long addr1;
	addr1=inet_addr(argv[1]);
	printf("addr1=%x\n",addr1);
	return 0;
}
 
