#include "dog.hpp"

Dog::Dog() : Animal()
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
	this->_type = src._type;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
	return (*this);
}

void Dog::getIdeas(void)const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Dog's Idea number " << i << ": " << this->_brain->getIdea(i) << std::endl;
}

void Dog::setIdea(unsigned int i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
