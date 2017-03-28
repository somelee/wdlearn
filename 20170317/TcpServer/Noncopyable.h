 ///
 /// @file    Noncopyable.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-18 09:49:43
 ///
 
#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
public:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &rhs);
	Noncopyable & operator=(const Noncopyable &rhs);
};

}

#endif
