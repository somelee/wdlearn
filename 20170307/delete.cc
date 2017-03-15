 ///
 /// @file    delete.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 09:36:45
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <fstream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::ofstream;

struct Fpclose
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "fclose(fp)" << endl;
		}
	}
};

struct OfstreamCloser
{
	void operator()(ofstream * ofs)
	{
		if(ofs)
		{
			ofs->close();
			cout << "ofstream close" << endl;
		}
	}
};

int test()
{
	shared_ptr<FILE> spFile(fopen("test.txt","rw+"),Fpclose());
	char buff[1024] = {};
	strcpy(buff,"hello");

	fwrite(buff,1,5,spFile.get());

	return 0;
}

int test1()
{
	unique_ptr<FILE,Fpclose> upFile(fopen("test.txt","a+"),Fpclose());
	char buff[1024] = {};
	strcpy(buff,"hello");

	fwrite(buff,1,5,upFile.get());

	return 0;
}

int main()
{
	ofstream ofs("test.txt",std::ios::app);
	unique_ptr<ofstream,OfstreamCloser> upOfstream(&ofs,OfstreamCloser());

	ofs << "hello";

	return 0;
}
