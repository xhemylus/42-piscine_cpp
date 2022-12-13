#include "phonebook.hpp"

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
	int index;
	std::string input;
	std::stringstream ss;

	std::cout << std::setfill (' ') << std::setw(10) << "INDEX";
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << "FIRSTNAME";
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << "LASTNAME";
	std::cout << "|" ;
	std::cout << std::setfill (' ') << std::setw(10) << "NICKNAME";
	std::cout << "|" << std::endl;

	for (int i = -1; ++i < 8;)
		contact[i].print(i);
	
	std::cout << "Insert contact index: ";
	std::getline(std::cin, input);
	ss << input;
	ss >> index;
	if (index > 8 || index < 0 || ss.fail())
		std::cout << "Wrong index." << std::endl;
	else
		contact[index].focus();
}

Phonebook::~Phonebook()
{
	delete[] contact;
}