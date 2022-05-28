#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{

}

Zombie::Zombie(std::string newname)
{
    name = newname;
}


void Zombie::announce (void) {

    if (name != "foo")
        std::cout << "<" << name << ">: BraiiiiiiinnnzzzZ..." << std::endl ;
    else 
        std::cout << "Foo: BraiiiiiiinnnzzzZ..." << std::endl;

}

void Zombie::assignName(std::string newname) {

    name = newname;
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed." << std::endl;
}