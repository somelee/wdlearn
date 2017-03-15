 ///
 /// @file    map_insert.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-03 14:24:07
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::multimap;
using std::pair;

int main1()
{
	map<int,string> mapIntStr = {
		pair<int,string>(1,"a"),
		pair<int,string>(2,"b")
	};

	pair<int,string> t(2,"x");

	pair<map<int,string>::iterator,bool> ret = mapIntStr.insert(t);
	if(ret.second)
	{
		cout << "数据插入成功" << endl;
	}else{
		cout << "数据插入失败，原容器中已有关键字相同的元素" << endl;
	}

	return 0;
}

int main()
{
	multimap<int,string> mapIntStr = {
		pair<int,string>(1,"a"),
		pair<int,string>(2,"b")
	};

	pair<int,string> t(1,"x");

	multimap<int,string>::iterator ret = mapIntStr.insert(t);
	cout << ret->first << "-->" << ret->second << endl << endl;

	for(auto & elem : mapIntStr)
	{
		cout << elem.first << "-->" << elem.second << endl;
	}

	return 0;
}
