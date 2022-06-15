#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string str)
{
    type = str;
}

Weapon::Weapon()
{
    type = "... nothing.";
}

std::string Weapon::getType(void)
{
    return (type);
}

void Weapon::setType(std::string newType)
{
    type = newType;
}

Weapon::~Weapon()
{
    
}