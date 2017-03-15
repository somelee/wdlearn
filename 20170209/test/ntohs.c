 ///
 /// @file    ntohs.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-09 14:10:40
 ///
 
#include "func.h"

int main()
{
	int port=0x1234;
	int nport;
	nport=htons(port);
	printf("nport=%x\n",nport);
	int hport;
	hport=ntohs(nport);
	printf("hport=%x\n",hport);
	return 0;
}
 
