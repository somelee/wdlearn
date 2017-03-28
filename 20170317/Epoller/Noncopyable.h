 ///
 /// @file    Noncopyable.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-26 10:49:22
 ///
 
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
public:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};

}
#endif
