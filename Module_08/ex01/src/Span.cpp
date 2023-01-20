#include "Span.hpp"

Span::Span() : _size(0)
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
	this->_size = src._size;
	this->_container = src._container;
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
		throw FullContainerException();
	this->_container.push_back(number);
}

void Span::addRandom()
{
	srand(time(NULL));
	while (this->_container.size() != this->_size)
		this->_container.push_back(rand());
}

void Span::addRangeOfIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator cur = begin;
	while (cur != end)
	{
		this->addNumber(*cur);
		cur++;
	}
}

int Span::shortestSpan()
{
	std::vector<int> tmp = this->_container;
	if (tmp.size() < 2)
		throw NotEnoughNumbersException();
	std::sort(tmp.begin(), tmp.end());
	int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	}
	return shortest;
}

int Span::longestSpan()
{
	std::vector<int> tmp = this->_container;
	if (tmp.size() < 2)
		throw NotEnoughNumbersException();
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::FullContainerException::what() const throw()
{
	return "Error: Container is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Error: Not enough numbers";
}

unsigned int Span::getSize() const
{
	return this->_size;
}

std::ostream &operator<<(std::ostream &out, Span &span)
{
	int shortest = span.shortestSpan();
	int longest = span.longestSpan();

	out << "Span of size :" << span.getSize() << std::endl << "Longest : " << longest << std::endl << "Shortest : " << shortest << std::endl;
	return out;
}
