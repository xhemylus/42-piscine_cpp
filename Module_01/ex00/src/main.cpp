#include <iostream>
#include <algorithm>
#include "Zombie.hpp"

int main()
{
    {
    Zombie travaldo("Travaldo");
    travaldo.announce();
    }
    
    randomChump("Robeto");

    Zombie* poulet = newZombie("poulet");
    poulet->announce();
    delete(poulet);
}