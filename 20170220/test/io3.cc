 ///
 /// @file    io3.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-23 19:19:56
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
	ifstream ifo("io1.cc");
	if(!ifo.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	vector<string> vecStr;
	vecStr.reserve(100);

	string str;
	while(getline(ifo,str))
	{
		vecStr.push_back(str);
	}

	for(auto & elem : vecStr)
	{
		cout << elem << endl;
	}

	ifo.close();
	return 0;
}
