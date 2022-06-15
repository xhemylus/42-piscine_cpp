#include "humanB.hpp"

HumanB::HumanB(std::string str)
{
    name = str;
}

void HumanB::attack(void)
{
    if (!weapon)
    {
        std::cout << name << " attacks with their... bare fists" << std::endl;
        return;
    }
    std::cout << name << " attacks with their " << weapon->type << std::endl;
};

void HumanB::setWeapon(Weapon& newweapon)
{
    weapon = &newweapon;
}

HumanB::~HumanB()
{
    
}