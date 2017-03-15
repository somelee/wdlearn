 ///
 /// @file    nestclass.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-26 20:37:29
 ///
 
#ifndef __NESTCLASS_H__
#define __NESTCLASS_H__

#include <iostream>
using std::endl;
using std::cout;

class Line
{
	class LineImpl;
public:
	Line(int x1,int y1,int x2,int y2);
	~Line();
	void printLine();
private:
	LineImpl * _pImpl;
};

#endif
