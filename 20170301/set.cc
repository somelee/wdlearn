 ///
 /// @file    set.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-02 20:49:51
 ///
 
#include <iostream>
#include <set>
#include <string>
using std::cout;
using std::endl;
using std::set;
using std::string;

int test()
{
	set<int,std::greater<int>> setInt = {2,1,3,5,4,6,3,5,6};
	set<int>::iterator sit;
	for(sit = setInt.begin();sit != setInt.end();++sit)
	{
		cout << *sit << " ";
	}
	cout << endl;

	return 0;
}

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
	friend bool operator<(const Point & lhs,const Point & rhs);
	friend bool operator>(const Point & lhs,const Point & rhs);
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

bool operator<(const Point & lhs,const Point & rhs)
{
	return lhs._ix < rhs._iy;
}

bool operator>(const Point & lhs,const Point & rhs)
{
	if(lhs._ix > rhs._ix)
		return true;
	else
		return false;
}


int main()
{
	set<Point,std::greater<Point>> setPoint = {
		Point(1,2),
		Point(3,4),
		Point(5,6),
		Point(1,2)
	};

	set<Point>::iterator sit;
	for(sit = setPoint.begin();sit != setPoint.end();++sit)
	{
		cout << *sit << " ";
	}
	cout << endl;

	return 0;
}
