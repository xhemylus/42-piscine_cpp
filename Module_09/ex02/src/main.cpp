#include "pmergeme.hpp"

bool odd = false;

int main (int argc, char **argv)
{
	PMergeMe pmm;
	try
	{
		if (argc < 2)
			throw BadUsage();
		pmm.holder(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}