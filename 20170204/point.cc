 ///
 /// @file    point.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-04 16:35:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point
{
public:
	Point(int ix,int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "void print() const" << endl;
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}

	void print()
	{
		cout << "void print()" << endl;
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

int main()
{
	Point pt(1,2);
	pt.print();

	const Point pt2(3,4);
	pt2.print();

	return 0;
}

