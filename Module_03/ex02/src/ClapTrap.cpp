#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("ClapTrap"), _hitpoint(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitpoint(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
};

void ClapTrap::attack(const std::string &target)
{
	std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage." << std::endl;;
}

int ClapTrap::check(void)
{
	if (_hitpoint < 1)
	{
		std::cout << _name << " is dead!" << std::endl;
		return (1);
	}
	if (_energyPoints < 1)
	{
		std::cout << _name <<": Not enough energy!" << std::endl;
		return (1);
	}
	return (0);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!check())
	{
		std::cout << _name << " took " << amount << " damage!" << std::endl;;
		_hitpoint -= amount;
		_energyPoints -= 1;
		std::cout << _name << " has now " << _hitpoint << " hp!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!check())
	{
		std::cout << _name << " repairs " << amount << " hp!" << std::endl;;
		_hitpoint += amount;
		_energyPoints -= 1;
		std::cout << _name << " has now " << _hitpoint << " hp!" << std::endl;;
	}
}