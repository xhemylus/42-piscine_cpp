#include <iostream>
#include <algorithm>

int	main(int argc, char** argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 0;
		while (++i < argc)
		{
			std::string str(argv[i]);
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return 0;
}