#include "wronganimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
		std::cout << "WrongAnimal constructor called." << std::endl;
		*this = src;
};

void WrongAnimal::makeSound(void)const
{
	std::cout << _type << " : Hello there. I'm a generic ... WrongAnimal." << std::endl;
}

std::string WrongAnimal::getType(void)const
{
	return(this->_type);
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}