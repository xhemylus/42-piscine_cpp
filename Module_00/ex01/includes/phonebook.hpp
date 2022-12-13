#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <sstream>

class Phonebook
{
public:
	Phonebook();
	~Phonebook();
private:
	Contact *contact;
	int	index;
public:
	void add();
	void search();
};

#endif