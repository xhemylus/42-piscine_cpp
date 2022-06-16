#include "animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound(void)const
{
	std::cout << _type << " : Hello there. I'm a generic Animal." << std::endl;
}

std::string Animal::getType(void)const
{
	return(this->_type);
}