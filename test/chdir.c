#include "func.h"

int main()
{
	int ret;
	ret=chdir("/hom");
	printf("ret=%d\n",ret);
	printf("%s\n",getcwd(NULL,0));
	return 0;
}
