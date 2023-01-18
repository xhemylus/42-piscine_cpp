#include "Array.hpp"

Array::Array() : _size(0)
{
	this->array = new T[this->_size];
}

Array::Array(unsigned int n) : _size(n)
{

	this->array = new T[this->_size];
}

Array::Array(const Array<T> &src) : _size(src.size)
{
	*this = src;
}

Array::~Array()
{
}

unsigned int Array::size()
{
	for (int i = 0; Array[i] ; i++;);
	return (i);
}