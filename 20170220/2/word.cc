#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::istringstream;

class WordStatistic
{
public:
	//将文件读入容器保存
	void readFile(string filename)
	{
		ifstream ifs(filename);
		if(!ifs.good())
		{
			cout << "ifstream open error!" << endl;
		}
		while(getline(ifs,str))
		{
			vecStr.push_back(str);
		}
	}
	//把词频容器打印输出
	void writeFile(string filename)
	{
		countFile();
		ofstream ofs(filename);
		if(!ofs.good())
		{
			cout << "ofstream open error!" << endl;
			ofs.close();
		}
		for(auto & wdct : wdcount)
		{
			ofs << wdct.word << "   " << wdct.count << endl;
		}
		ofs.close();
	}
private:
	//统计词频
	void countFile()
	{
		ofstream ofs("fil");
		for(auto & elem : vecStr)//把每行分别从容器里取出
		{
			for(auto & c : elem)//把每行的信息依次拿出来判断是否为字母
			{
				if(c<97)//若为大写字母加为小写
				{
					c+=32;
				}
				if(97>c || c>122)//除字母以外的都改成空格
				{
					c=32;
				}
			}
			istringstream iss(elem);
			int i=0;
			vector<struct wd>::iterator it;
			while(iss >> str)
			{
			ofs << str << endl;
				for(it=wdcount.begin();it!=wdcount.end();++it)
				{
					if(it->word==str)
					{
						++(it->count);
						break;
					}
				}
				if(it==wdcount.end())
				{

					wdct.word=str;
					wdct.count=1;
					wdcount.push_back(wdct);
				}
//				for(auto & wdct : wdcount )
//				{
//					if(str==wdct.word)
//					{
//						++wdct.count;
//						break;
//					}
//					++i;
//				}
//				if(wdcount.size()==i)
//				{
//					wdct.word=str;
//					wdct.count=1;
//					wdcount.push_back(wdct);
//				}
			}
		}
		ofs.close();
	}
private:
	string str;//文件每行写进str，然后放入容器
	vector<string> vecStr;//存储文件每行的容器
	struct wd{
		string word;//单词
		int count;//出现次数
	};
	struct wd wdct;
	vector<struct wd> wdcount;//统计词频的容器
};
int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		cout << "args error." << endl;
		return -1;
	}
	cout << argv[1] << " " << argv[2] << endl;
	WordStatistic v;
	v.readFile(argv[1]);
	cout << "count" << endl;
	v.writeFile(argv[2]);
	return 0;
}
