#ifndef ARRAY_HPP
#define ARRAY_HPP


template <class T>
class Array
{
private:
	T* Array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& src);
	~Array();

	Array& operator=(const Array<T> src);



	unsigned int size();

};

#endif