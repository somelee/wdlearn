 ///
 /// @file    memory.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-02 20:15:24
 ///
#include <stdio.h> 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0;
char * p1;

void test()
{
	static int d = 100;
	++d;
	cout << "d = " << d << endl;
}

int main()
{
	int b;
	char s[] = "123456";
	char * p2;
	const char * p3 = "123456";

	static int c = 0;

	printf("&a = %p\n",&a);
	printf("&p1 = %p\n",&p1);
	printf("p1 = %p\n",p1);
	printf("&p2 = %p\n",&p2);
	printf("&p3 = %p\n",&p3);
	printf("&p3 = %p\n",p3);
	printf("&b = %p\n",&b);
	printf("s = %p\n",s);
	printf("&c = %p\n",&c);
	printf("&a = %p\n",&a);

	p1 = new char[10];
	p2 = new char[5];
	printf("p1 = %p\n",p1);
	printf("*p1 = %d\n",*p1);
//	printf("sizeof(p1) = %d\n",strlen(p1));
	printf("p2 = %p\n",p2);
	printf("*p2 = %d\n",*p2);
//	printf("sizeof(p2) = %d\n",strlen(p2));
	test();
	test();
	strcpy(p1,"123456");
	printf("sizeof(p1) = %d\n",sizeof(p1));
	printf("sizeof(*p1) = %d\n",sizeof(*p1));
	printf("strlen(p1) = %d\n",strlen(p1));
	printf("sizeof(s) = %d\n",sizeof(s));
	printf("sizeof(*s) = %d\n",sizeof(*s));
	printf("strlen(s) = %d\n",strlen(s));
	return 0;
}
