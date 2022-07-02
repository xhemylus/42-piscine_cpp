#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const ClapTrap & src);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap & operator=(const ClapTrap & src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int	check(void);
private:
	std::string _name;
	unsigned int _hitpoint;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif