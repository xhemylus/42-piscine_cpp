#include "contact.hpp"
#include <iostream>

Contact::Contact()
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
}

Contact::~Contact()
{

}