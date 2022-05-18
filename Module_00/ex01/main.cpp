#include <iostream>
#include <algorithm>
#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;
	while (1)
	{
		std::cout << "=== PHONEBOOK ===" << std::endl << "> ";
		std::cin >> command;
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			return 0;
		else
			std::cout << "Command not found." << std::endl;
	}

}