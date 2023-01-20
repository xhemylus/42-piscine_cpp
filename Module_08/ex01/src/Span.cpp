#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(unsigned int n) : _size(n)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const & src)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span & Span::operator=(Span const & src)
{
	if (this == &src)
		return *this;
	this->_size = src._size;
	this->_container = src._container;
	return *this;
}

void Span::addNumber(int number)
{
	if (this->_container.size() == this->_size)
		throw ErrorException();
	this->_container.push_back(number);
}

int Span::shortestSpan()
{
	if (this->_container.size() < 2)
		throw ErrorException();
	std::sort(this->_container.begin(), this->_container.end());
	int shortest = this->_container[1] - this->_container[0];
	for (unsigned int i = 1; i < this->_container.size() - 1; i++)
	{
		if (this->_container[i + 1] - this->_container[i] < shortest)
			shortest = this->_container[i + 1] - this->_container[i];
	}
	return shortest;
}

int Span::longestSpan()
{
	if (this->_container.size() < 2)
		throw ErrorException();
	std::sort(this->_container.begin(), this->_container.end());
	return (this->_container[this->_container.size() - 1] - this->_container[0]);
}

const char *Span::FullContainerException::what() const throw()
{
	return "Error: Container is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Error: Not enough numbers";
}
