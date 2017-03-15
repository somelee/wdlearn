 ///
 /// @file    string.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-03 21:01:18
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
private:
	char * _pstr;

public:
	String()
	: _pstr(new char[1])
	{}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) +1])
	{
		strcpy(_pstr,pstr);
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1])
	{
		strcpy(_pstr,rhs._pstr);
	}

	String & operator=(const String & rhs)
	{
		if(this == &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	~String()
	{
		delete [] _pstr;
	}

	void print()
	{
		cout << _pstr << endl;
	}
};

int main()
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3 = "wangdao";

	str2.print();
	str3.print();
	str2 = str3;
	str2.print();

	String str4 = str3;
	str4.print();

	return 0;
}
