 ///
 /// @file    weak_ptr.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-07 19:40:08
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Parent;
class Child
{
public:
	Child()
	{
		cout << "Child()" << endl;
	}

	~Child()
	{
		cout << "~Child()" << endl;
	}

	weak_ptr<Parent> _parentPtr;
};

class Parent
{
public:
	Parent()
	{
		cout << "Parent()" << endl;
	}

	~Parent()
	{
		cout << "~Parent()" << endl;
	}

	shared_ptr<Child> _childPtr;
};

int main()
{
	shared_ptr<Parent> sParent(new Parent);
	cout << "sParent`s use_count() = " << sParent.use_count() << endl;
	shared_ptr<Child> sChild(new Child);
	cout << "sChild`s use_count() = " << sChild.use_count() << endl;

	sParent->_childPtr = sChild;
	sChild->_parentPtr = sParent;

	cout << "sChild`s use_count() = " << sChild.use_count() << endl;
	cout << "sParent`s use_count() = " << sParent.use_count() << endl;

	return 0 ;
}
