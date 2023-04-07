#include "rpn.hpp"

rpn::rpn()
{
};

rpn::rpn(rpn const &src)
{
	*this = src;
};

rpn &rpn::operator=(rpn const &src)
{
	this->_stack = src._stack;
	return *this;
};

rpn::~rpn()
{
};

int rpn::Calculate(int a, int b, char op)
{
	std::cout << a << " " << b << " " << op << std::endl;
	switch (op)
	{
	case '+':
		return (a + b);
	case '-':
		return (b - a);
	case '*':
		return (a * b);
	case '/':
	{
			if (a == 0)
				throw std::runtime_error("Division by zero");
		return (b / a);
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
			int a = _stack.top();
			_stack.pop();
			if (_stack.empty())
				throw std::runtime_error("Invalid input");
			_stack.push(Calculate(a, _stack.top(), input[i]));

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