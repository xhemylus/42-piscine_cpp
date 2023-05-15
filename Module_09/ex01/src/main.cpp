#include "rpn.hpp"

int main(int argc, char **argv)
{
	rpn calc;
	try
	{
		if (argc != 2)
			throw Badusage();
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