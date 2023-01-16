#include "conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "One Argument required." << std::endl;
		return (1);
	}
	try
	{
		Conversion conversion(argv[1]);
	}
	catch(const Conversion::ErrorException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}