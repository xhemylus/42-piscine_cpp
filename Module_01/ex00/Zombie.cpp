#include "Zombie.hpp"
#include <iostream>

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

Zombie::~Zombie()
{
    std::cout << name << " destroyed." << std::endl;
}