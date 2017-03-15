 ///
 /// @file    templateConvert.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-01 19:29:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#if 0
template <typename T1,typename T2>
class Convert
{
public:
	T2 execute(T1 data)
	{
		return T2(data);
	}
};
#endif

template <typename T1>
class Convert
{
public:
	template <typename T2>
	T2 execute(T1 data);
#if 0
	{
		return T2(data);
	}
#endif
};

template <typename T1>
template <typename T2>
T2 Convert<T1>::execute(T1 data)
{
	return T2(data);
}

int main()
{
#if 0
	Convert<char,int> convert;
	cout << convert.execute('a') << endl;
#endif

	Convert<char> convert;
	cout << convert.execute<int>('a') << endl;

	return 0;
}
