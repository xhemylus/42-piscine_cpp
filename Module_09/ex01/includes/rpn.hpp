#pragma once

#include <stack>
#include <string>
#include <iostream>

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
	int Calculate(char op);
};