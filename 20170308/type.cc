 ///
 /// @file    type.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 23:50:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

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

	//Point & operator=(const Point & rhs);
	
	void display()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	int getX() const
	{
		return _ix;
	}

	int getY() const
	{
		return _iy;
	}
private:
	int _ix;
	int _iy;
};

class Point3D
:public Point
{
public:
	Point3D(int ix,int iy,int iz)
	:Point(ix,iy)
	,_iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	~Point3D()
	{
		cout << "~Point3D()" << endl;
	}

	//Point3D & operator=(const point3D & rhs);
	
	void display()
	{
		cout << "(" << getX()
			 << "," << getY()
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};

int main()
{
	cout << "sizeof(Point) = " << sizeof(Point) << endl;
	cout << "sizeof(Point3D) = " << sizeof(Point3D) << endl;
	Point pt1(1,2);

	pt1.display();
	Point3D pt2(3,4,5);
	pt2.display();
	cout << endl;

	Point * p = &pt2;
	p->display();
}
