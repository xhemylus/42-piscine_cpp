#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	void makeSound(void)const;
};

#endif