 ///
 /// @file    iterator_error.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 17:20:51
 ///
 
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> vecStr;
	vecStr.push_back("this is A");
	cout << "vec`s capacity = " << vecStr.capacity() << endl;

	bool flag = true;
	vector<string>::iterator it;
	for(it = vecStr.begin();it != vecStr.end();++it)
	{
		cout << "vec`s size = " << vecStr.size() << endl;
		cout << "vec`s capacity = " << vecStr.capacity() << endl;
		cout << *it << endl;

		if(flag)
		{
			vecStr.push_back("this is B");
			cout << "vec`s capacity = " << vecStr.capacity() << endl;
			flag = false;
		}
	}

	return 0;
}
