#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitpoint = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "FragTrap constructor created." << std::endl;
};

FragTrap::FragTrap(const FragTrap &src)
{
		std::cout << "FragTrap constructor called." << std::endl;
		*this = src;
};

void FragTrap::highFivesGuys()
{
	std::cout << _name << " requests an High Five !" << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitpoint = src._hitpoint;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}
