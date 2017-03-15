 ///
 /// @file    RAII.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 16:30:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class RAII
{
public:
	RAII(T * p)
	:_p(p)
	{
		cout << "RAII()" << endl;
	}

	T * operator->()
	{
		return _p;
	}

	T & operator*()
	{
		return *_p;
	}

	T * get()const
	{
		return _p;
	}

	~RAII()
	{
		if(_p)
			delete _p;
	}
private:
	RAII(const RAII &);
	RAII & operator=(const RAII &);
private:
	T * _p;
};

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void display()const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main()
{
	RAII<int> pInt(new int(3));

	cout << "*pInt = " << *pInt << endl;

	RAII<Point> pPoint(new Point(1,2));

	pPoint->display();

	return 0;
}
