#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
public:
	Contact();
	~Contact();
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string	phonenumber;
	std::string	darkest_secret;
};
#endif