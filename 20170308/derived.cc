 ///
 /// @file    derived.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-09 00:11:36
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	:_pdata(new char[1])
	{
		cout << "Base()" << endl;
	}

	Base(const char * pdata)
	:_pdata(new char[strlen(pdata) + 1])
	{
		cout << "Base(const char *)" << endl;
		strcpy(_pdata,pdata);
	}

	Base(const Base & rhs)
	:_pdata(new char[strlen(rhs._pdata) + 1])
	{
		cout << "Base(const Base &)" << endl;
		strcpy(_pdata,rhs._pdata);
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base &)" << endl;
		if(this != &rhs)
		{
			delete [] _pdata;
			_pdata = new char[strlen(rhs._pdata) +1 ];
			strcpy(_pdata,rhs._pdata);
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _pdata;
	}

	friend std::ostream & operator<<(std::ostream & os, const Base & rhs);
private:
	char * _pdata;
};

class Derived
:public Base
{
public:
	Derived(const char * pdata,const char * pdata2)
	:Base(pdata)
	,_pdata2(new char[strlen(pdata2) + 1])
	{
		cout << "Derived(const char *)" << endl;
		strcpy(_pdata2,pdata2);
	}

	Derived(const Derived & rhs)
	:Base(rhs)
	,_pdata2(new char[strlen(rhs._pdata2) + 1])
	{
		cout << "Derived(const Derived &)" << endl;
		strcpy(_pdata2,rhs._pdata2);
	}

	Derived & operator=(const Derived & rhs)
	{
		cout << "Derived & operator=(const Derived &)" << endl;
		if(this != &rhs)
		{
			Base::operator=(rhs);

			delete [] _pdata2;
			_pdata2 = new char[strlen(rhs._pdata2) + 1];
			strcpy(_pdata2,rhs._pdata2);
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os,const Derived & rhs);
private:
	char * _pdata2;
};

std::ostream & operator<<(std::ostream & os,const Base & rhs)
{
	os << rhs._pdata;
	return os;
}

std::ostream & operator<<(std::ostream & os,const Derived & rhs)
{
	os << (Base)rhs << " " << rhs._pdata2;
	return os;
}

int main(void)
{
	Derived d1("hello",",world");
	cout << "d1 = " << d1 << endl;

	Derived d2 = d1;
	cout << "d2 = " << d2 << endl;
	cout << endl;

	Derived d3("shenzhen","wangdao");
	cout << "d3 = " << d3 << endl;

	d3 = d1;
	cout << "d3 = " << d3 << endl;

	return 0;
}
