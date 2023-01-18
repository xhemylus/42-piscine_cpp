#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array() : _size(0)
	{
		this->_array = new T[this->_size];
	}
	Array(unsigned int n) : _size(n)
	{
		this->_array = new T[this->_size];
	}
	Array(const Array<T> &src) : _size(src.size())
	{
		this->_array = NULL;
		*this = src;
	}
	~Array()
	{
		if (this->_array != NULL)
			delete[] this->_array;
	}

	Array &operator=(const Array &src)
	{
		if (this->_array != NULL)
			delete[] this->_array;
		if (src.size() != 0)
		{
			this->_size = src._size;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->size(); i++)
				this->_array[i] = src._array[i];
		}
		return *this;
	}

	T &operator[](unsigned int i)
	{
		if (this->size() <= i || this->_array == NULL)
			throw Array::InvalidIndexException();
		return (this->_array[i]);
	}

	class InvalidIndexException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	unsigned int size() const
	{
		return (this->_size);
	}
};

template <typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
	return ("Invalid Index");
}
