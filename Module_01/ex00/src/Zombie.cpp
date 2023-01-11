#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string newname)
{
	name = newname;
}

void Zombie::announce(void)
{

	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed." << std::endl;
}