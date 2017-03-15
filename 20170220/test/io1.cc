 ///
 /// @file    io1.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-23 17:08:06
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;

void printCin()
{
	cout << "cin`s badbit = " << cin.bad() << endl;
	cout << "cin`s failbit = " << cin.fail() << endl;
	cout << "cin`s eofbit = " << cin.eof() << endl;
	cout << "cin`s goodbit = " << cin.good() << endl;
}

int main()
{
	int num;
	printCin();
	while(cin >> num)
	{
		cout << "num = " << num << endl;
	}
	printCin();

	cout << endl;
	cin.clear();
	cout << "---------------------" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	printCin();
	cout << endl;

	cin >> num;
	cout << "num1 = " << num << endl;
	printCin();

	return 0;
}
