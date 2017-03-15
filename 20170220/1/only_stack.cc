#include <iostream> 
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;

class Student
{
public:
	Student(int num,const char* name)
	:_nu(num)
	,_name(new char[strlen(name) + 1])
	{
		cout << "Student()" << endl;
		strcpy(_name,name);
	}
	~Student()
	{
		cout << "~Student()" << endl;
		if(NULL!=_name)
		{
			delete [] _name;
			_name=NULL;
		}
	}
	void print()
	{
		cout << "num:" << _nu << endl;
		cout << "name:" << _name << endl;
	}
private:
	void * operator new(size_t size);
	void operator delete(void *p);
private:
	int _nu;
	char* _name;
};

int main()
{
	Student s1(101,"jacker");
	s1.print();

//	Student * s2 = new Student(100,"Mile");
//	s2->print();
//	delete s2;

	return 0;
}
