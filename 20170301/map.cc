 ///
 /// @file    map.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 09:43:17
 ///
 
#include <iostream>
#include <string.h>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

int main()
{
	pair<int,string> (600036,"招商银行");
	cout << first << "-->" << second << endl;

	map<int,string> mapIStr = {
		pair<int,string>(1,"北京"),
		pair<int,string>(2,"深圳"),
		pair<int,string>(3,"广州"),
		pair<int,string>(2,"苏州")
	};

	map<int,string>::iterator mit;
	for(mit = mapIStr.begin();mit != mapIStr.end();++mit)
	{
		cout << mit->first << "-->" << mit->second << endl;
	}

	cout << mapIStr[2] << endl;
	cout << mapIStr[4] << "--" << endl;
	mapIStr[4] = "上海";
	cout << mapIStr[4] << "--" << endl;



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

int test1()
{
	map<Point,string,std::greater<Point>> mapIStr = {
		pair<Point,string>(Point(1,2),"北京"),
		pair<Point,string>(Point(2,3),"深圳"),
		pair<Point,string>(Point(3,4),"上海"),
		pair<Point,string>(Point(3,4),"苏州")
	};

	for(auto & elem : mapIStr)
	{
		cout << elem.first << "-->" << elem.second << endl;
	}
	cout << endl;

	return 0;
}

int main2()
{
	map<string,int> mapstr;
	 map<string,int>::iterator mit;
	 for(mit = mapstr.begin();mit != mapstr.end();++mit)
	 {
		 if(!strcmp("str",mit->first.c_str()))
			 break;
	 }
	 if(mit == mapstr.end())
	 {
		 mapstr["str"] = 1;
	 }

	for(auto & elem : mapstr)
	{
		cout << elem.first << "-->" << elem.second << endl;
	}
	cout << endl;
	 return 0;
}
