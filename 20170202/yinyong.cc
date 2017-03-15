 ///
 /// @file    yinyong.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-02 15:47:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int i = 10;
	int &j = i;
	int &k = j;
	int &l = k;

	cout << i << " , " << j << " , " << k << " , " << l << endl;
	j++;
	cout << i << " , " << j << " , " << k << " , " << l << endl;
	k++;
	cout << i << " , " << j << " , " << k << " , " << l << endl;
	l++;
	cout << i << " , " << j << " , " << k << " , " << l << endl;
	return 0;
}

