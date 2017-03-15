/*
this is lib.h. it declares the functions fred and bill for users
*/
#include<stdio.h>

void bill(char *);
void fred(int);

void bill(char *arg)
{
	printf("bill: we passed %s\n",arg);
}
