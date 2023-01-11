#include "dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog(const Dog &src)
{
		std::cout << "Dog constructor called." << std::endl;
		*this = src;
};

void Dog::makeSound(void)const
{
	std::cout << this->getType() << " : Bark Bark !" << std::endl;
}

Dog & Dog::operator=(const Dog & src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}