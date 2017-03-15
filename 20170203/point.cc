 ///
 /// @file    point.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-03 15:43:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	explicit
	Point(int ix = 0,int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int = 0,int iy = 0)" << endl;
	}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	void print()
	{
		cout << "(" << _ix << " , " << _iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

void func(Point pt)
{
	cout << "void func(Point pt)" << endl;
	pt.print();
}

int getInt()
{
	int a = 1;
	return a;
}

Point getPoint()
{
	Point pt(3,4);
	pt.print();
	return pt;
}

int main()
{
	Point p;
	Point pt1(1,2);
	pt1.print();

	Point pt2(pt1);
	pt2.print();
	func(pt2);

	cout << endl;
	Point pt3 = getPoint();
	pt3.print();

	return 0;

}

