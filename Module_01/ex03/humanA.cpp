#include "humanA.hpp"
#include <iostream>

HumanA::HumanA(std::string newname, Weapon& newweapon) : weapon(newweapon)
{
    name = newname;
    weapon = newweapon;
}

// HumanA::HumanA()
// {
//     name = "Travaldo";
//     weapon = Weapon();
// }

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weapon.type << std::endl;
}

HumanA::~HumanA()
{

}