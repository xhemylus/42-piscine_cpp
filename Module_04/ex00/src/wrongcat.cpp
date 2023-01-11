#include "wrongcat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
		std::cout << "WrongCat constructor called." << std::endl;
		*this = src;
};

void WrongCat::makeSound(void)const
{
	std::cout << this->getType() << " : I'm not a cat..." << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}