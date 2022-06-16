#include "cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound(void)const
{
	std::cout << this->getType() << " : Purrr Purrr !" << std::endl;
}