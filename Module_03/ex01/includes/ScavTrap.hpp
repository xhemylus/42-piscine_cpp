#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap & src);
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap & operator=(const ScavTrap & src);

	void guardGate();
private:
	int isGuard;
};

#endif