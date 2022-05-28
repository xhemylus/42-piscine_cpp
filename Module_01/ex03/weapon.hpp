#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
    Weapon(std::string str);
    ~Weapon();
    Weapon();
    std::string getType(void);
    void setType(std::string newType);
	std::string type;
};

std::string getType(void);
void setType(std::string);

#endif