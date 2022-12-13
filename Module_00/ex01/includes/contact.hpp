#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
public:
	Contact();
	~Contact();
	void	create(void);
	void	print(int index);
	void	focus(void);
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string	phonenumber;
	std::string	darkest_secret;
	int isCreated;
};


#endif