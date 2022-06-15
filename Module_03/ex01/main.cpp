#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap lzrd("Lézard");
    ScavTrap bite("Poulet");

    lzrd.attack("Bite");
    lzrd.takeDamage(3);
    lzrd.beRepaired(2);

    bite.attack("Bite");
    bite.takeDamage(3);
    bite.beRepaired(2);



}