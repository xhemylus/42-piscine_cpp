#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitpoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created." << std::endl;
};

void ScavTrap::guardGate()
{
	if (isGuard)
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
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}