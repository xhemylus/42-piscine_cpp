#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack()
	{
		std::cout << "MutantStack constructor called" << std::endl;
	};
	MutantStack(const MutantStack<T> &src)
	{
		std::cout << "MutantStack copy constructor called" << std::endl;
		*this = src;
	};
	~MutantStack()
	{
		std::cout << "MutantStack destructor called" << std::endl;
	};

	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack<T> &operator=(const MutantStack<T> &src)
	{
		(void)src;
		return *this;
	};

	typename std::stack<T>::container_type::iterator begin()
	{
		return (this->c.begin());
	};

	typename std::stack<T>::container_type::iterator end()
	{
		return (this->c.end());
	};
};
