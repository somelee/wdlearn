 ///
 /// @file    string.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-24 19:35:25
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class String
{
	friend bool operator==(const String &,const String &);
	friend bool operator!=(const String &,const String &);

	friend bool operator<(const String &,const String &);
	friend bool operator>(const String &,const String &);

	friend bool operator<=(const String &,const String &);
	friend bool operator>=(const String &,const String &);

	friend std::ostream & operator<<(std::ostream & os,const String & rhs);
	friend std::istream & operator>>(std::istream & is,String & rhs);

	friend String operator+(const String &,const String &);
	friend String operator+(const String &,const char*);
	friend String operator+(const char*,const String &);
public:
	String()
	:_pstr(new char[1])
	{
		cout << __FUNCTION__ << endl;
	}

	String(const char* pstr)
	:_pstr(new char[strlen(pstr) + 1])
	{
		cout << __FUNCTION__ << endl;
		strcpy(_pstr,pstr);
	}

	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr) + 1])
	{
		cout << __FUNCTION__ << endl;
		strcpy(_pstr,rhs._pstr);
	}

	~String()
	{
		cout << __FUNCTION__ << endl;
		if(NULL != _pstr)
		{
			delete [] _pstr;
			_pstr = NULL;
		}
	}

	String & operator=(const String & rhs)
	{
		cout << __FUNCTION__ << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	String & operator=(const char* pstr)
	{
		cout << __FUNCTION__ << endl;
		delete [] _pstr;
		_pstr = new char[strlen(pstr) + 1];
		strcpy(_pstr,pstr);
	}

	String & operator+=(const String & rhs)//没必要判断 str += str；
	{
		cout << __FUNCTION__ << endl;
		char* tmp = _pstr;
		_pstr = new char[strlen(tmp) + strlen(rhs._pstr) + 1];
		sprintf(_pstr,"%s%s",tmp,rhs._pstr);
		return *this;
	}

	String & operator+=(const char* pstr)
	{
		cout << __FUNCTION__ << endl;
		char* tmp = _pstr;
		_pstr = new char[strlen(tmp) + strlen(pstr) + 1];
		sprintf(_pstr,"%s%s",tmp,pstr);
		return *this;
	}

	char & operator [](int idx)
	{
		cout << __FUNCTION__ << endl;
		if(idx >= 0 && idx < strlen(_pstr))
		{
			return _pstr[idx];
		}else{
			cout << "下标越界" << endl;
		}
	}

	const char & operator[](int idx) const
	{
		cout << __FUNCTION__ << endl;
		if(idx >= 0 && idx < strlen(_pstr))
		{
			return _pstr[idx];
		}else{
			cout << "下标越界" << endl;
		}
	}

	std::size_t size() const
	{
		cout << __FUNCTION__ << endl;
		return strlen(_pstr);
	}

	const char* c_str() const
	{
		cout << __FUNCTION__ << endl;
		return _pstr;
	}
private:
	char* _pstr;
};

bool operator==(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	return 0 == strcmp(lhs._pstr,rhs._pstr);
}

bool operator!=(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	return 0 != strcmp(lhs._pstr,rhs._pstr);
}

bool operator<(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	return strcmp(lhs._pstr,rhs._pstr) < 0;
}

bool operator>(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	return strcmp(lhs._pstr,rhs._pstr) > 0;
}

bool operator<=(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	return strcmp(lhs._pstr,rhs._pstr) <= 0;
}

bool operator>=(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	return strcmp(lhs._pstr,rhs._pstr) >= 0;
}

std::ostream & operator<<(std::ostream & os,const String & s)
{
		cout << __FUNCTION__ << endl;
	os << s._pstr;
	return os;
}

std::istream & operator>>(std::istream & is,String & s)
{
		cout << __FUNCTION__ << endl;
	char tmp[1000]={};
	is >> tmp;
	s._pstr = new char[strlen(tmp) + 1];
	strcpy(s._pstr,tmp);
	return is;
}

String operator+(const String & lhs,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	String tmp;
	tmp._pstr = new char[lhs.size() + rhs.size() +1];
	sprintf(tmp._pstr,"%s%s",lhs.c_str(),rhs.c_str());
	return tmp;
}

String operator+(const String & lhs,const char* pstr)
{
		cout << __FUNCTION__ << endl;
	String tmp;
	tmp._pstr = new char[lhs.size() + strlen(pstr) + 1];
	sprintf(tmp._pstr,"%s%s",lhs._pstr,pstr);
	return tmp;
}

String operator+(const char* pstr,const String & rhs)
{
		cout << __FUNCTION__ << endl;
	String tmp;
	tmp._pstr = new char[strlen(pstr) + rhs.size() + 1];
	sprintf(tmp._pstr,"%s%s",pstr,rhs._pstr);
	return tmp;
}


int main()
{
		cout << __FUNCTION__ << endl;
	String str = "hello";

	str = str + " word";

	String str1 = "I am lee";

	cout << str << str1 << endl;

	return 0;
}
