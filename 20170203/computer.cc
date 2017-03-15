 ///
 /// @file    computer.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-03 16:55:41
 ///

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
		cout << "Computer(const char * brand,float price)" << endl;
	}

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1])
	, _price(rhs._price)
	{
		strcpy(_brand,rhs._brand);
		cout << "Computer(const Compter &)" << endl;
	}

	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & oprator=(const Computer &)" << endl;
		if(this != &rhs)
		{
			delete [] _brand;

			_brand = new char[strlen(rhs._brand) + 1];
			strcpy(_brand,rhs._brand);
			this->_price = rhs._price;
		}
		return *this;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

	void print()
	{
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}


private:
	char * _brand;
	float  _price;
};

int main()
{
	Computer pc1("Thinkpad",5000);
	pc1.print();
	
	Computer pc2 = pc1;
	pc2.print();
	cout << endl;

	Computer pc3("Mac",10000);
	pc3.print();
	pc3 = pc1;

	cout << "pc3 = pc3" << endl;
	pc3 = pc3;
	pc3.print();
	
	return 0;
}
