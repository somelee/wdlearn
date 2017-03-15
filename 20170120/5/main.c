#include<stdio.h>

void print(int *i)
{
	*i=-5;
}

int main(int argc,char* argv[])
{
	int i;
	i=10;
	int *p;
	p=&i;
	print(p);
	p=NULL;
	printf("the value is %d\n",*p);
	return 0;
}
