 ///
 /// @file    io5.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-23 19:59:45
 ///
 

#include <iostream>
#include <fstream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;

int test1()
{
	ofstream ofs("abc.txt",std::ios::app);
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return -1;
	}
	int pos = ofs.tellp();
	cout << "pos = " << pos << endl;
	string str = "that's new";

	ofs << str;

	ofs.close();
	return 0;
}

int test2()
{
	ifstream ifs("io1.cc",std::ios::ate);
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	int pos = ifs.tellg();
	cout << "pos = " << pos << endl;

	return 0;
}

int main()
{
	fstream fs("abc.txt");
	if(!fs.good())
	{
		cout << "fstream open error!" << endl;
		return -1;
	}

	int ival;
	for(int idx = 0;idx != 10;++idx)
	{
		cin >> ival;
		fs << ival << ' ';
	}
	int pos = fs.tellp();
	cout << "pos = " << pos << endl;
	fs.seekg(0,std::ios::beg);
	cout << "pos = " << fs.tellg() << endl;

	for(int idx = 0;idx != 10;++idx)
	{
		fs >> ival;
		cout << ival << ' ';
	}
	cout << endl;

	fs.close();

	return 0;
}
