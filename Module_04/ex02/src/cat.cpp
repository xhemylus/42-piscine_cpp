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
	this->_type = src._type;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
	return (*this);
}


void Cat::getIdeas(void)const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Cat's Idea number " << i << ": " << this->_brain->getIdea(i) << std::endl;
}

void Cat::setIdea(unsigned int i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
