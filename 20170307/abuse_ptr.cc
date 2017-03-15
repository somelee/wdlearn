 ///
 /// @file    abuse_ptr.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 23:52:13
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;

class Point
:public std::enable_shared_from_this<Point>
{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void display()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	shared_ptr<Point> addPoint(const Point * pt)
//	Point addPoint(const Point * pt)
	{
		this->_ix += pt->_ix;
		this->_iy += pt->_iy;
		return shared_from_this();
//		return *this;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main1()
{
	Point * pt = new Point(1,2);
//	shared_ptr<Point> spPtr(pt);
//	shared_ptr<Point> spPtr2(pt);

	unique_ptr<Point> spPtr(pt);
	unique_ptr<Point> spPtr2(pt);
	return 0;
}

int main()
{
	Point * pt = new Point(1,2);
	Point * pt2 = new Point(3,4);

	shared_ptr<Point> spPtr(pt);
	shared_ptr<Point> spPtr2(pt2);

	shared_ptr<Point> spPtr3(spPtr->addPoint(spPtr2.get()));

	return 0 ;
}
