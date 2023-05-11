#include "rpn.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./ex01 \"<expression>\"" << std::endl;
		return 1;
	}
	rpn calc;
	try
	{
		calc.ParseInput(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	std::cout << "Online tester : https://t.ly/-ZtK" << std::endl;
	return 0;
}