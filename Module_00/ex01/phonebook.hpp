#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"
class Phonebook
{
public:
	Phonebook();
	~Phonebook();
private:
	Contact *contact;
	int	index;
};

#endif