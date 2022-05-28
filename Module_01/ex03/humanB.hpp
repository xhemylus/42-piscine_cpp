#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void attack(void);
    void setWeapon(Weapon& weapon);
private:
	std::string name;
    Weapon *weapon;
};

void attack(void);
void setWeapon(Weapon& weapon);

#endif