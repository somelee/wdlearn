 ///
 /// @file    Point2.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-25 21:14:55
 ///
 //
 

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;


class Line;

class Point
{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	void func(Line & line);

	int _ix;
	int _iy;
};

class Line
{
public:
	float distance(const Point & p1,const Point & p2)
	{
		return sqrt((p1._ix - p2._ix) * (p1._ix - p2._ix) +
				(p1._iy + p2._iy) * (p1._iy - p2._iy));
	}

	void setPoint(Point * pt,int ix,int iy)
	{
		pt->_ix = ix;
		pt->_iy = iy;
	}
private:
	int _iz;
};

void Point::func(Line & line)
{
	cout << line._iz << endl;
}

int main()
{
	Point pt1(1,2);
	Point pt2(3,4);

	Line line;

	pt1.print();
	cout << "--->";
	pt2.print();
	cout << "的距离："
		 << line.distance(pt1,pt2) << endl;

	line.setPoint(&pt2,5,6);

	pt2.print();

	return 0;
}
