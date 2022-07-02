#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
	: _name("ClapTrap"), _hitpoint(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap construcor created." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &src)
{
		std::cout << "ClapTrap constructor called." << std::endl;
		*this = src;
};

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitpoint(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor created." << std::endl;
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
		std::cout << "Not enough energy!" << std::endl;
		return (1);
	}
	return (0);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoint < 1)
	{
		std::cout << _name << " is dead!" << std::endl;
		return;
	}
		std::cout << _name << " took " << amount << " damage!" << std::endl;;
		if (amount > _hitpoint)
			amount = _hitpoint;
		_hitpoint -= amount;
		std::cout << _name << " has now " << _hitpoint << " hp!" << std::endl;
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

ClapTrap & ClapTrap::operator=(const ClapTrap & src)
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