#include <stdio.h> 
#include <stdlib.h>
int main()
{
	char* p;
	if((p=getenv("inet addr")))
		printf("USER=%s\n",p);
	return 0;
}
