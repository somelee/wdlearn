 ///
 /// @file    Noncopyable.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-14 20:17:40
 ///
 
#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};

}

#endif
