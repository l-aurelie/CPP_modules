#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
public:
	Array<T>(void): _elements(NULL), _size(0) 
	{}
	Array<T>(Array<T> const &array)
	{
		*this = array;
	}
	Array<T>(unsigned int n): _elements(new T[n]), _size(n)
	{
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = 0;
	}
	~Array<T>(void) { delete [] _elements;}

	Array<T> &operator=(Array<T> const &array)
	{
		if (this == &array)
			return (*this);
		_size = array._size;
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = array._elements[i];
		return (*this);
	}
	T &operator[](unsigned int const &idx) const
	{
		if (idx >= _size)
			throw std::out_of_range("index is greater than array size");
		return (_elements[idx]);
	}

	unsigned int size(void) const 
	{ 
		return (_size); 
	}

private:
	T *_elements;
	unsigned int _size;
};


template<>
class Array<char>
{
public:
	Array<char>(void) : _elements(NULL), _size(0)
	{}
	Array<char>(Array<char> const &array)
	{
		*this = array;
	}
	Array<char>(unsigned int n) : _elements(new char[n]), _size(n)
	{
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = 'a';
	}
	~Array<char>(void) { delete [] _elements;}

	Array<char> &operator=(Array<char> const &array)
	{
		if (this == &array)
			return (*this);
		_size = array._size;
		_elements = new char[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = array._elements[i];
		return (*this);
	}
	char &operator[](unsigned int const &idx) const
	{
		if (idx >= _size)
			throw std::out_of_range("index is greater than array size");
		return (_elements[idx]);
	}

	unsigned int size(void) const 
	{ 
		return (_size); 
	}

private:
	char *_elements;
	unsigned int _size;
};
#endif
