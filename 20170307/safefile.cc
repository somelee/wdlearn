 ///
 /// @file    safefile.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 16:14:23
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
	SafeFile(FILE * fp)
	:_fp(fp)
	{
		cout << "SafeFile(FILE *)" << endl;
	}

	~SafeFile()
	{
		if(_fp)
		{
			fclose(_fp);
			cout << "~SafeFile()" << endl;
		}
	}

	void write(const string & msg)
	{
		fwrite(msg.c_str(),1,msg.size(),_fp);
	}

	string read()
	{
		char buf[1000] = {};
		fread(buf,1000,5,_fp);

		return string(buf);
	}

private:
	FILE * _fp;
};

int main()
{
	SafeFile sf(fopen("test.txt","rw+"));

	string msg = "hello,world";
	sf.write(msg);

	cout << sf.read() << endl;

	return 0;
}
