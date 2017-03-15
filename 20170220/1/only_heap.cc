#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int num,const char* name)
	:_num(num)
	,_name(new char[strlen(name) + 1])
	{
		cout << "Student()" << endl;
		strcpy(_name,name);
	}
	void print()
	{
		cout << "num:" << _num << endl;
		cout << "name:" << _name << endl;
	}
	void destory()
	{
		cout << "void destory()" << endl;
		delete this;
	}
private:
	~Student()
	{
		cout << "~Student()" << endl;
		delete [] _name;
	}
private:
	int _num;
	char* _name;
};

int main()
{
	Student *p=new Student(1001,"liming");
	p->print();

	p->destory();

	return 0;
}
