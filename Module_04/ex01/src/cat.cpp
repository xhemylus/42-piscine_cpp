#include "cat.hpp"
#include "brain.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound(void)const
{
	std::cout << this->getType() << " : Purrr Purrr !" << std::endl;
}