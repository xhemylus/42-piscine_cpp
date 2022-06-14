#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>;

class ClapTrap
{
public:
	ClapTrap(std::string name);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string _name;
	unsigned int _hitpoint;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif