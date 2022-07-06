#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{


	ClapTrap lzrd("Lézard");
	lzrd.attack("Jeff");
	lzrd.takeDamage(3);
	lzrd.beRepaired(2);


	ScavTrap jeff("Jeffrey");
	jeff.attack("Michel");
	jeff.takeDamage(3);
	jeff.beRepaired(2);
	jeff.guardGate();
	jeff.guardGate();


	FragTrap yuu("Yuu");
	yuu.attack("Jo");
	yuu.takeDamage(3);
	yuu.beRepaired(2);
	yuu.highFivesGuys();
}