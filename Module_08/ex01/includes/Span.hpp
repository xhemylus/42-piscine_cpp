#pragma once

#include <iostream>
#include <vector>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &src);

	void addNumber(int number);

	int shortestSpan();
	int longestSpan();

	void addRandom();
	void addRangeOfIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	unsigned int getSize() const;

	class FullContainerException : public std::exception
	{
		public: 
			virtual const char *what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
		public: 
			virtual const char *what() const throw();
	};


private:
	std::vector<int> _container;
	unsigned int _size;
};

std::ostream &operator<<(std::ostream &out, const Span &span);