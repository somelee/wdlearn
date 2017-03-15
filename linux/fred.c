/*
this is lib.h. it delares the functions fred and bill for users
*/

#include<stdio.h>

void bill(char *);
void fred(int);

void fred(int arg)
{
	printf("fred: we passed %d\n",arg);
}

