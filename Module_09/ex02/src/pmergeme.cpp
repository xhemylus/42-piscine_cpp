#include "pmergeme.hpp"

PMergeMe::PMergeMe()
{
	odd = false;
}

PMergeMe::~PMergeMe()
{
}

PMergeMe::PMergeMe(PMergeMe const &src)
{
	*this = src;
}

PMergeMe &PMergeMe::operator=(PMergeMe const &src)
{
	if (this != &src)
	{
		this->vect = src.vect;
		this->list = src.list;
		this->tmp = src.tmp;
		this->odd = src.odd;
	}
	return *this;
}

void PMergeMe::isUnsigned(char *str1, char *str2)
{
	std::string string1(str1);
	std::string string2(str2);
	if (string1.find_first_not_of("0123456789") != std::string::npos || string2.find_first_not_of("0123456789") != std::string::npos)
		throw InvalidInput();
}

void PMergeMe::holder(int argc, char **argv)
{
	std::cout << "Before: ";
	// if (argc < 6)
	// {
	// 	for (int i = 1; i < argc; i++)
	// 		std::cout << argv[i] << " ";
	// 	std::cout << std::endl;
	// }
	// else 
	// {
	// 	for (int i = 1; i < 6; i++)
	// 		std::cout << argv[i] << " ";
	// 	std::cout << "[...]" << std::endl;
	// }

	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	if ((argc - 1) % 2 != 0)
	{
		odd = true;
		std::string string1(argv[argc - 1]);
		if (string1.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInput();
		tmp = std::atoi(argv[argc - 1]);

		argc--;
	}

	for (int i = 1; i < argc; i+=2)
	{
		isUnsigned(argv[i], argv[i + 1]);
		vect.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
	}
	for (int i = 1; i < argc; i+=2)
	{
		isUnsigned(argv[i], argv[i + 1]);
		list.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
	}

	std::vector<unsigned int> a;
	std::vector<unsigned int> b;
	std::deque<unsigned int> c;
	std::deque<unsigned int> d;
	vecsort(argc, vect, a, b, tmp, odd, 1);

	vecsort(argc, list, c, d, tmp, odd, 0);


}