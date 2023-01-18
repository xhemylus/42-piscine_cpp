#include "iter.hpp"

void tolower(char &c)
{
	c = std::tolower(static_cast<unsigned char>(c));
}

void toupper(char &c)
{
	c = std::toupper(static_cast<unsigned char>(c));
}

void incr(int &i)
{
	i++;
}

int main()
{
	char array[3] = {'A', 'B', 'C'};

	std::cout << "- - - - - - Old Array - - - - - -" << std::endl;
	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;
	std::cout << array[2] << std::endl;
	::iter(array, 3, tolower);
	std::cout << "- - - - - - New Array - - - - - -" << std::endl;
	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;
	std::cout << array[2] << std::endl;
	::iter(array, 3, toupper);
	std::cout << "- - - - - - New Array - - - - - -" << std::endl;
	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;
	std::cout << array[2] << std::endl;
	std::cout << "= = = = = = = = = = = = = = = = =" << std::endl << std::endl;

	int array2[5] = {0, 0, 0, 0, 0};
	std::cout << "- - - - - - Old Array - - - - - -" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array2[i] << std::endl;
	::iter(array2, 5, incr);
	std::cout << "- - - - - - New Array - - - - - -" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array2[i] << std::endl;
	::iter(array2, 5, incr);
		std::cout << "- - - - - - New Array - - - - - -" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array2[i] << std::endl;
}