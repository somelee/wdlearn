 ///
 /// @file    computer.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-03 10:50:26
 ///

#include <unistd.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand,float price)
	: _brand(new char[strlen(brand) + 1])
	, _price(price)
	{
		strcpy(_brand,brand);
		cout << "Computer(const char * brand,float)" << endl;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "~Compter()" << endl;
	}

	void print()
	{
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}
private:
	char * _brand;
	float _price;
};

Computer pcGlobal("HP",7000);

int test1()
{
	{
		Computer com("Thinkpad",5000);
		com.print();
	}

	sleep(2);

	cout << "hello,word" << endl;

	return 0;
}

void test2()
{
	Computer * pc = new Computer("Mac",1000);
	pc->print();
	pcGlobal.print();
	delete pc;
}
int main()
{
	test1();
	test2();
	return 0;
}
