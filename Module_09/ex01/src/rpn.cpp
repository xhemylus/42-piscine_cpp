#include "rpn.hpp"

rpn::rpn(){};

rpn::rpn(rpn const &src)
{
	*this = src;
};

rpn &rpn::operator=(rpn const &src)
{
	this->_stack = src._stack;
	return *this;
};

rpn::~rpn(){};

int rpn::Calculate(char op)
{
	int n2 = _stack.top();
	_stack.pop();
	if (_stack.empty())
		throw std::runtime_error("Invalid input");
	int n1 = _stack.top();
	_stack.pop();
	switch (op)
	{
	case '+':
		return (n1 + n2);
	case '-':
		return (n1 - n2);
	case '*':
		return (n1 * n2);
	case '/':
	{
		if (n2 == 0)
			throw std::runtime_error("Division by zero");
		return (n1 / n2);
	}
	default:
		throw std::runtime_error("Invalid operator");
	}
};

void rpn::ParseInput(std::string input)
{
	std::string operators = "+-*/";
	int num = 0;
	int ope = 0;


	for (size_t i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			num++;
			_stack.push(input[i] - '0');
		}
		else if (operators.find(input[i]) != std::string::npos)
		{
			ope++;
			_stack.push(Calculate(input[i]));
		}
		else if (input[i] == ' ')
			continue;
		else
			throw std::runtime_error("Invalid input");
	}
	if (ope + 1 != num)
		throw std::runtime_error("Invalid input");
	std::cout << _stack.top() << std::endl;
}