#include "pmergeme.hpp"

PMergeMe::PMergeMe()
{
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
	if (isdigit(*str1) == 0 || isdigit(*str2) == 0)
		throw std::runtime_error("Invalid arguments");
	if (std::atoi(str1) < 0 || std::atoi(str2) < 0)
		throw std::invalid_argument("Invalid arguments");
}

void PMergeMe::holder(int argc, char **argv)
{
	if ((argc - 1) % 2 != 0)
	{
		odd = true;
		if(std::atoi(argv[argc - 1]) < 0)
			throw std::invalid_argument("Invalid arguments");
		tmp = std::atoi(argv[argc - 1]);
		argc--;
	}
	std::cout << "Before: ";
	if (argc < 6)
	{
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " " << std::endl;
	}
	else 
	{
		for (int i = 1; i < 6; i++)
			std::cout << argv[i] << " ";
		std::cout << "[...]" << std::endl;
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