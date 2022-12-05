#include "contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
	isCreated = 0;
}

void	Contact::print(int index)
{
	if (!firstname.empty())
	{
		std::cout << std::setfill (' ') << std::setw(10) << index;
		std::cout << "|";
		if (firstname.size() > 10)
		{
			std::string firstname2 = firstname.substr(0, 9);
			firstname2.append(".");
			std::cout << std::setfill (' ') << std::setw(10) << firstname2;
		}
		else
			std::cout << std::setfill (' ') << std::setw(10) << firstname;
		std::cout << "|";
		if (lastname.size() > 10)
		{
			std::string lastname2 = lastname.substr(0, 9);
			lastname2.append(".");
			std::cout << std::setfill (' ') << std::setw(10) << lastname2;
		}
		else
			std::cout << std::setfill (' ') << std::setw(10) << lastname;
		std::cout << "|";
		if (nickname.size() > 10)
		{
			std::string nickname2 = nickname.substr(0, 9);
			nickname2.append(".");
			std::cout << std::setfill (' ') << std::setw(10) << nickname2;
		}
		else
			std::cout << std::setfill (' ') << std::setw(10) << nickname;
		std::cout << "|" << std::endl;
	}
}

void Contact::focus(void)
{
	if (isCreated)
	{
		std::cout << "=== CONTACT INFO ===" << std::endl;
		std::cout << "firstname: " << firstname << std::endl;
		std::cout << "lastname: " << lastname << std::endl;
		std::cout << "nickname: " << nickname << std::endl;
		std::cout << "phone number: " << phonenumber << std::endl;
		std::cout << "darkest secret: " << darkest_secret << std::endl;
	}
	else
		std::cout << "Contact is not created." << std::endl;
	std::cout << "--------------------" << std::endl;
}

void Contact::create(void)
{
	std::cout << "=== New Contact ===" << std::endl;
	std::cout << "contact's firstname: ";
	std::cin >> firstname;
	std::cout << firstname << "'s lastname: ";
	std::cin >> lastname;
	std::cout << firstname << " " << lastname << "'s nickname: ";
	std::cin >> nickname;
	std::cout << firstname << " " << lastname << "'s phone number: ";
	std::cin >> phonenumber;
	std::cout << firstname << " " << lastname << "'s darkest secret: ";
	std::cin >> darkest_secret;
	std::cout << "====== Saved ======" << std::endl << "-------------------" << std::endl;
	isCreated = 1;
}

Contact::~Contact()
{

}