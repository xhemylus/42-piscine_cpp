#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook()
	: index(-1)
{
	contact = new Contact[8];
}

void Phonebook::add(void)
{
	index++;
	if (index > 7)
		index = 0;
	contact[index].create();
}

void Phonebook::search(void)
{
	int input;

	int i = -1;
	std::cout << std::setfill (' ') << std::setw(10) << "INDEX";
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << "FIRSTNAME";
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << "LASTNAME";
	std::cout << "|" ;
	std::cout << std::setfill (' ') << std::setw(10) << "NICKNAME";
	std::cout << "|" << std::endl;
	while (++i < 8)
		contact[i].print(i);
	std::cout << "Insert contact index: ";
	std::cin >> input;
	if (std::cin.fail() || input > 8 || input < 0)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Wrong index." << std::endl;
	}
	else
		contact[input].focus();
}

Phonebook::~Phonebook()
{
	delete[] contact;
}