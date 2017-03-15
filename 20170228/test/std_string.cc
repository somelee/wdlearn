 ///
 /// @file    std_string.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-28 15:52:24
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1 = "hello,world";
	string s2 = "aflsegvlisehvlhvldsrh";
	string s3 = s1;

	cout << "sizeof(s1) = " << sizeof(s1) << endl;
	cout << "sizeof(s2) = " << sizeof(s2) << endl;

	const char * p1 = s1.c_str();
	const char * p2 = s2.c_str();
	const char * p3 = s3.c_str();
	printf("p1 = %p\n",p1);
	cout << s1 << endl;
	printf("p2 = %p\n",p2);
	cout << s2 << endl;
	printf("p3 = %p\n",p3);
	cout << s3 << endl;

	cout << s3[0] << endl;
	p1 = s1.c_str();
	p2 = s2.c_str();
	p3 = s3.c_str();
	printf("p1 = %p\n",p1);
	cout << s1 << endl;
	printf("p2 = %p\n",p2);
	cout << s2 << endl;
	printf("p3 = %p\n",p3);
	cout << s3 << endl;
	cout << "做修改操作：" << endl;

	s3[0] = 'X';
	p1 = s1.c_str();
	p2 = s2.c_str();
	p3 = s3.c_str();
	printf("p1 = %p\n",p1);
	cout << s1 << endl;
	printf("p2 = %p\n",p2);
	cout << s2 << endl;
	printf("p3 = %p\n",p3);
	cout << s3 << endl;

	return 0;
}
