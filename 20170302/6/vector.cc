 ///
 /// @file    vector.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-04 21:24:53
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
	Vector()
	:_elem(NULL)
	,_first_free(NULL)
	,_end(NULL)
	{}

	~Vector()
	{
		while(_first_free != _elem)
			_alloc.destroy(--_first_free);
		_alloc.deallocate(_elem,capacity());
	}

	void push_back(const T & value);
	void pop_back();

	size_t size() const
	{
		return _first_free - _elem;
	}

	size_t capacity() const
	{
		return _end - _elem;
	}

	T & operator[](size_t idx)
	{
		return *(_elem + idx);
	}
private:
	void reallocate();
private:
	static std::allocator<T> _alloc;

	T * _elem;
	T * _first_free;
	T * _end;
};

template <typename T>
std::allocator<T>  Vector<T>::_alloc;

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(_first_free == _end)
	{
		reallocate();
	}

	_alloc.construct(_first_free++,value);
}

template <typename T>
void Vector<T>::reallocate()
{
	size_t sz = size();
	size_t newcapacity = (sz > 0 ? 2 * sz : 1);

	T * newElem = _alloc.allocate(newcapacity);
	std::uninitialized_copy(_elem,_first_free,newElem);

	if(_elem)
	{
		while(_first_free != _elem)
			_alloc.destroy(--_first_free);
		_alloc.deallocate(_elem,sz);
	}

	_elem = newElem;
	_first_free = _elem + sz;
	_end = _elem + newcapacity;
}

template <typename T>
void Vector<T>::pop_back()
{
	if(_first_free != _elem)
		_alloc.destory(--_first_free);
}

int main()
{
	Vector<int> vecInt;
	cout << "vecInt`s size = " << vecInt.size() << endl;
	cout << "vecInt`s capa = " << vecInt.capacity() << endl;

	vecInt.push_back(1);
	cout << "vecInt`s size = " << vecInt.size() << endl;
	cout << "vecInt`s capa = " << vecInt.capacity() << endl;

	vecInt.push_back(2);
	cout << "vecInt`s size = " << vecInt.size() << endl;
	cout << "vecInt`s capa = " << vecInt.capacity() << endl;

	vecInt.push_back(3);
	cout << "vecInt`s size = " << vecInt.size() << endl;
	cout << "vecInt`s capa = " << vecInt.capacity() << endl;

	for(size_t idx = 0;idx != vecInt.size();++idx)
	{
		cout << vecInt[idx] << " ";
	}
	cout << endl;

	return 0;
}
