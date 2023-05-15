#pragma once

#include <stack>
#include <string>
#include <iostream>

#define red "\033[1;31m"
#define white "\033[0;37m"
#define reset "\033[0;0m"
#define orange "\033[1;33m"

class rpn
{
private:
	std::stack<float> _stack;
public:
	rpn();
	rpn(rpn const &src);
	rpn &operator=(rpn const &src);
	~rpn();


	void ParseInput(std::string input);
	float Calculate(char op);
};

class Badusage : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (orange "Usage: " white "./ex01 \"<expression>\"" reset);
	}
};

class InvalidInput : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (red "Error: " white "Invalid input" reset);
	}
};

class DivisionByZero : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (red "Error: " white "Division by zero" reset);
	}
};
