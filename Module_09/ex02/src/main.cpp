#include "pmergeme.hpp"

bool odd = false;

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "No arguments" << std::endl;
		return 1;
	}
	PMergeMe pmm;
	try
	{
		pmm.holder(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}