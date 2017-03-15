 ///
 /// @file    getcwd.c
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-15 23:30:24
 ///
#include <stdio.h> 
#include <unistd.h>

int main()
{
	char buf[100];
	getcwd(buf,100);
	printf("%s\n",buf);
	return 0;
}
