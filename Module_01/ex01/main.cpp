#include <iostream>
#include <algorithm>
#include "Zombie.hpp"

int main()
{
    Zombie* zombie = zombieHorde(10, "Travaldo");

    for (int i = 0; i < 10; i++)
        zombie[i].announce();
    delete[] zombie;
}