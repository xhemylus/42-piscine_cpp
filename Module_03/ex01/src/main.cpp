#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap lzrd("Lézard");
    ScavTrap jeff("Jeffrey");

    lzrd.attack("Jeff");
    lzrd.takeDamage(3);
    lzrd.beRepaired(2);

    jeff.attack("Michel");
    jeff.takeDamage(3);
    jeff.beRepaired(2);
    jeff.guardGate();
    jeff.guardGate();



}