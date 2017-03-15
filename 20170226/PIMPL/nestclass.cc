 ///
 /// @file    nestclass.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 20:43:04
 ///
 
#include "nestclass.h"
#include <iostream>
using std::endl;
using std::cout;

class Line::LineImpl
{
private:
	class Point
	{
	public:
		Point(int ix = 0,int iy = 0)
		:_ix(ix)
		,_iy(iy)
		{
			cout << "Line::LineImpl::Point(int,int)" << endl;
		}

		void printPoint();
	private:
		int _ix;
		int _iy;
	};
public:
	LineImpl(int x1,int y1,int x2,int y2);

	void printLine();

private:
	Point _p1;
	Point _p2;
};

Line::LineImpl::LineImpl(int x1,int y1,int x2,int y2)
:_p1(x1,y1)
,_p2(x2,y2)
{
	cout << "LineImpl(int,int,int,int)" << endl;
}

void Line::LineImpl::Point::printPoint()
{
	cout << "(" << _ix << "," << _iy << ")";
}

void Line::LineImpl::printLine()
{
	_p1.printPoint();
	cout << "-->";
	_p2.printPoint();
	cout << endl;
}

Line::Line(int x1,int y1,int x2,int y2)
:_pImpl(new LineImpl(x1,y1,x2,y2))
{
	cout << "Line(int,int,int,int)" << endl;
}

Line::~Line()
{
	cout << "~Line()" << endl;
	delete _pImpl;
}

void Line::printLine()
{
	_pImpl->printLine();
}

int main()
{
	Line line(1,2,3,4);
	line.printLine();
	cout << endl;

	return 0;
}
