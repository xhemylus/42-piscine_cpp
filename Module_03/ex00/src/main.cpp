#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap lzrd("Lézard");

    lzrd.attack("Jeff");
    for (int i = 0; i < 11; i++)
        lzrd.beRepaired(1);
    lzrd.takeDamage(3);
    lzrd.takeDamage(10);
    lzrd.takeDamage(10);
    lzrd.beRepaired(20);

}