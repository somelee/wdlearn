 ///
 /// @file    static.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-04 15:48:24
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
		_totalPrice += _price;
		cout << "Computer(float)" << endl;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		delete [] _brand;
		_totalPrice -= _price;
	}

	static void printTotalPrice()
	{
		
		cout << "_totalPrice:" << _totalPrice << endl;
	}

	static void print(Computer & com)
	{
		cout << "brand:" << com._brand << endl;
		cout << "price:" << com._price << endl;
	}

private:
	char * _brand;
	float _price;
	static float _totalPrice;
};

float Computer::_totalPrice = 0.0;

int main()
{
	Computer pc1("Tiankpad",5000);
	Computer::print(pc1);
	Computer::printTotalPrice();

	Computer pc2("Mac",10000);
	Computer::printTotalPrice();
	Computer::print(pc2);

	Computer pc3("HP",6000);
	Computer::printTotalPrice();
	Computer::print(pc3);

	cout << "sizeof(pc1) = " << sizeof(pc1) << endl;

	return 0;
}
