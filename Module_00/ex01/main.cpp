#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
	std::string command;
	while (1)
	{
		std::cout << "=== PHONEBOOK ===" << std::endl << "> ";
		std::cin >> command;
		if (command == "ADD")
			Contact contact;
		else if (command == "SEARCH")
			Phonebook phonebook;
		else if (command == "EXIT")
			return 0;
		else
			std::cout << "Command not found." << std::endl;
	}

}