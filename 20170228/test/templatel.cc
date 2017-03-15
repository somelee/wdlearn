 ///
 /// @file    templatel.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-01 16:00:51
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
	friend Point operator+(const Point & lhs,const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

Point operator+(const Point & lhs,const Point & rhs)
{
	return Point(lhs._ix + rhs._ix,lhs._iy + rhs._iy);
}

template <typename T>
T add(T x,T y)
{
	cout << "T add(T,T)" << endl;
	return x + y;
}

template <>
const char * add(const char * x,const char * y)
{
	char * ptmp = new char(strlen(x) + strlen(y) + 1);
	strcpy(ptmp,x);
	strcat(ptmp,y);
	return ptmp;
}

int add(int x,int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}

double add(double x,double y)
{
	cout << "double add(double,double)" << endl;
	return x + y;
}

template <typename T,int NUM>
T fun(T a)
{
	return a * NUM;
}

int main()
{
	int a = 3,b = 4;
	cout << "a + b = " << add(a,b) << endl;

	double x = 1.21,y = 2.34;
	cout << "x + y = " << add(x,y) << endl;

	Point pt1(1,2);
	Point pt2(3,4);
	cout << "pt1 + pt2 = " << add(pt1,pt2) << endl;

	cout << fun<int,10>(a) << endl;
	cout << fun<int,100>(a) << endl;

	const char * p1 = "hello";
	const char * p2 = "world";

	cout << add<const char *>(p1,p2) << endl;

	return 0;
}
