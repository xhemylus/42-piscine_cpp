#include "dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called." << std::endl;
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound(void)const
{
	std::cout << this->getType() << " : Bark Bark !" << std::endl;
}