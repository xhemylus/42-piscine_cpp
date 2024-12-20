#ifndef FragTRAP_HPP
#define FragTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& src);

	FragTrap& operator=(const FragTrap& src);
	
	~FragTrap();
	void highFivesGuys();
};

#endif