#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog & src);
	void makeSound(void)const;

	Dog & operator=(const Dog & src);
};

#endif