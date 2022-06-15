#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap lzrd("Lézard");

    lzrd.attack("Bite");
    lzrd.takeDamage(3);
    lzrd.beRepaired(2);

}