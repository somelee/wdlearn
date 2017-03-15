 ///
 /// @file    String.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-28 19:58:39
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::endl;
using std::cout;


class String
{
private:
	class CharProxy
	{
	public:
		CharProxy(int idx,String & str)
		:_idx(idx)
		,_str(str)
		{
			cout << "CharProxy(int,String)" << endl;
		}

		CharProxy & operator=(char ch);

		operator char()
		{
			cout << "operator char()" << endl;
			return _str._pstr[_idx];
		}
	//	friend std::ostream & operator<<(std::ostream & os,const CharProxy & rhs);
	private:
		int _idx;
		String & _str;
	};
	friend std::ostream & operator<<(std::ostream & os,const String & rhs);
//	friend std::ostream & operator<<(std::ostream & os,const CharProxy & rhs);
public:
	String();
	String(const String & rhd);
	String(const char* pstr);
	~String();

	String & operator=(const String & rhs);

	int size()const
	{
		return strlen(_pstr);
	}

	const char*  c_str()const
	{
		return _pstr;
	}

	int useCount()const
	{
		return _pstr[size() + 1];
	}

	void initRefCount()
	{
		_pstr[size() + 1] = 1;
	}

	void increaseRefcount()
	{
		++_pstr[size() + 1];
	}

	void decreaseRefcount()
	{
		--_pstr[size() + 1];
	}

	CharProxy operator[](int idx);
private:
	char* _pstr;
};

String::String()
:_pstr(new char[2])
{
	initRefCount();
}

String::String(const char * pstr)
:_pstr(new char[strlen(pstr) + 2])
{
	strcpy(_pstr,pstr);
	initRefCount();
}

String::String(const String & rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String::~String()
{
	if(0 ==_pstr[size() + 1])
	{
		delete [] _pstr;
	}
}

String & String::operator=(const String & rhs)
{
	if(this == &rhs)
		return *this;
	decreaseRefcount();
	if(0 == useCount())
		delete [] _pstr;
	_pstr = rhs._pstr;
	increaseRefcount();
	return *this;
}

String::CharProxy  String::operator[](int idx)
{
	cout << "String::operator[](int)" << endl;
	return CharProxy(idx,*this);
}

String::CharProxy & String::CharProxy::operator=(char ch)
{
	cout << "String::CharProxy::operator=(char)" << endl;
	if(_idx >= 0 && _idx < _str.size())
	{
		if(_str.useCount() > 1)
		{
			_str.decreaseRefcount();
			char * ptmp = new char[_str.size() + 2];
			strcpy(ptmp,_str._pstr);
			_str._pstr = ptmp;
			_str.initRefCount();
		}
		_str._pstr[_idx] = ch;
	}else{
		cout << "下标访问越界" << endl;
	}
	return *this;
}

#if 0
std::ostream & operator<<(std::ostream & os,const String::CharProxy & rhs)
{
	cout << "operator<<(std::ostream,const String::CharProxy)" << endl;
	os << rhs._str._pstr[rhs._idx];
	return os;
}
#endif
std::ostream & operator<<(std::ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}

int main()
{
	String s1 = "hello,world";
	String s2 = s1;
	String s3 = s2;

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	cout << "s1`s use count = " << s1.useCount() << endl;
	cout << "s2`s use count = " << s2.useCount() << endl;
	cout << "s3`s use count = " << s3.useCount() << endl;
	cout << endl;

	String s4 = "shenzhen";
	String s5 = s4;
	s5 = s3;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl;
	cout << "s4`s use count = " << s4.useCount() << endl;
	cout << "s5`s use count = " << s5.useCount() << endl;
	cout << "s1`s use count = " << s1.useCount() << endl;
	printf("&s4 = %p\n",s4.c_str());
	printf("&s5 = %p\n",s5.c_str());

	cout << endl << "发生写操作之后：" << endl;
	s1[0] = 'X';
	cout << "s1 = " << s1 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	cout << "s1`s use count = " << s1.useCount() <<endl;
	cout << "s2`s use count = " << s2.useCount() << endl;
	cout << "s3`s use count = " << s3.useCount() << endl;

	s4[0] = 'Y';
	cout << "s4 = " << s4 << endl;
	cout << "s4`s use cout = " << s4.useCount() << endl;
	printf("&s4 = %p\n",s4.c_str());

	cout << endl << "发生读操作：" << endl;
	cout << s2[0] << endl;
	cout << "s2`s use count = " << s2.useCount() << endl;
	cout << "s3`s use count = " << s3.useCount() << endl;
	cout << "s5`s use count = " << s5.useCount() << endl;
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());

	return 0;
}
