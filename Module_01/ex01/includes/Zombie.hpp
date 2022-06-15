#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    Zombie();
	Zombie(std::string);
    ~Zombie();
    void announce (void);
    void assignName(std::string name);
private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif