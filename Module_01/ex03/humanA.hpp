#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "weapon.hpp"

class HumanA
{
public:
    //HumanA();
    HumanA(std::string newname, Weapon& weapon);
    ~HumanA();
    void attack(void);
private:
    Weapon &weapon;
	std::string name;
};

void attack(void);

#endif