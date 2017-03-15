 ///
 /// @file    io6.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-23 20:58:14
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
using std::cout;
using std::endl;
using std::cin;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::string;

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

int main()
{
	int i1 = 512;
	int i2 = 1024;
	stringstream ss;
	ss << "i1 = " << i1 << ",i2 = " << i2;

	string s = ss.str();
	cout << s << endl;

	int tmp;
	while(!ss.eof())
	{
		ss >> s >> tmp;
		cout << s << tmp << endl;
	}
	cout << ss << endl;
	sleep(3);

	s = int2str(1000);
	cout << "s = " << s << endl;

	return 0;

}
