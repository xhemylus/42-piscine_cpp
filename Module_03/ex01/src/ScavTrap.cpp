#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitpoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->isGuard = 0;
	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
		std::cout << "ScavTrap constructor called." << std::endl;
		*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->isGuard = 0;
	std::cout << "ScavTrap constructor created." << std::endl;
};

void ScavTrap::guardGate()
{
	if (!isGuard)
	{
		std::cout << "ScavTrap " << _name << " entered Gate Keeper mode." << std::endl;
		isGuard = 1;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " left Gate Keeper mode." << std::endl;
		isGuard = 0;
	}
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src)
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
