#include "cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat &src)
{
		std::cout << "Cat constructor called." << std::endl;
		*this = src;
};

void Cat::makeSound(void)const
{
	std::cout << this->getType() << " : Purrr Purrr !" << std::endl;
}

Cat & Cat::operator=(const Cat & src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}