 ///
 /// @file    templateNest.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-01 20:15:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename O>
class Outside
{
public:
	template <typename I>
	class Inside
	{
	public:
		Inside(I i)
		:_i(i)
		{
			cout << "Inside()" << endl;
		}

		void display()
		{
			cout << "Inside:" << _i << endl;
		}
	private:
			I _i;
	};
public:
	Outside(O o)
	:_in(o)
	{
		cout << "Outside()" << endl;
	}

	void display()
	{
		cout << "Outside:";
		_in.display();
	}
private:
	Inside<O> _in;
};

int main()
{
	Outside<int>::Inside<double> inside(3.5);
	inside.display();

	Outside<int> outside(1);
	outside.display();

	return 0;
}
