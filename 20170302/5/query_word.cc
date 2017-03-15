 ///
 /// @file    query_word.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-04 10:04:13
 ///
 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;
using std::vector;
using std::map;
using std::set;
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::istringstream;

class TextQuery
{
public:
	void readFile(const string & filename);
	void query(const string & word);
	void display(const map<string,int>::iterator & mitFreq,const set<int> & setLine);
private:
	vector<string> _vecLines;
	map<string,set<int>> _mapWord2Line;
	map<string,int> _mapWordFreq;
};

void TextQuery::readFile(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl; 
	}
	string str;
	string word;
	map<string,int>::iterator mit;
	int lineCount = 0;
	while(getline(ifs,str))//每次从文件里读取一行
	{
		++lineCount;//记录当前的行号
		_vecLines.push_back(str);//把每行原句存入_vecLines中
		for(auto & c : str)//取出每个字符进行预处理
		{
			//对文本进行预处理，把文档变成只有空格和小写单词
			if(c < 97)
			{
				c += 32;
			}
			if(97 > c || c > 122)
			{
				c = 32;
			}
		}
		istringstream iss(str);//把每行拆成单词放入word中
		while(iss >> word)
		{
			//统计词频
			mit = _mapWordFreq.find(word);
			if(mit == _mapWordFreq.end())
			{
				_mapWordFreq[word] = 1;
			}else{
				++mit->second;
			}
			//统计出现在哪一行
			_mapWord2Line[word].insert(lineCount);
		}
	}
}

void TextQuery::query(const string & word)
{
	map<string,int>::iterator mitFreq;
	mitFreq = _mapWordFreq.find(word);
	if(mitFreq == _mapWordFreq.end())
	{
		cout << word << "is inexistence!" << endl;
		return;
	}
	map<string,set<int>>::iterator mitLine;
	mitLine = _mapWord2Line.find(word);
	set<int> setLine = mitLine->second;
	display(mitFreq,setLine);
	return;
}

void TextQuery::display(const map<string,int>::iterator & mitFreq,const set<int> & setLine)
{
	cout << "-----------------------------------" << endl;
	cout << mitFreq->first << " occurs " << mitFreq->second << " times." << endl;
	set<int>::iterator sit;
	for(sit = setLine.begin();sit != setLine.end();++sit)
	{
		cout << "    (line " << *sit << ") " << _vecLines[*sit - 1] << endl;
	}
	cout << "-----------------------------------" << endl;
}

int main()
{
	cout << "Please input filename:" << endl;
	string str;
	cin >> str;
	TextQuery tq;
	tq.readFile(str);
	while(1)
	{
		cout << "Please input word:" << endl; 
		cin >> str;
		tq.query(str);
	}

	return 0;
}
