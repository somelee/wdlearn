 ///
 /// @file    Point3D.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-08 19:37:33
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

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	int getX() const
	{
		return _ix;
	}

protected:
	int getY() const
	{
		return _iy;
	}
private:
	int _ix;
	int _iy;
};

class Point3D
:protected Point
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
	Point3D p3D(1,2,3);

	cout << "x = " << p3D.getX() << endl;
	//cout << "y = " << p3D.getY() << endl;

	p3D.print();

	Point pt(1,2);

	//pt.getY();

	return 0;
}
