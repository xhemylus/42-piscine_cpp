#pragma once

#include <iostream>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &src);

	addNumber(int number);

	shortestSpan();
	longestSpan();

	class FullContainerException : public std::exception
	{
		public: 
			virtual const char *what() const throw();
	}

	class NotEnoughNumbersException : public std::exception
	{
		public: 
			virtual const char *what() const throw();
	}

private:
	int *_container;
	unsigned int _size;
}