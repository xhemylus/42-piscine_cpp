#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	void makeSound(void)const;
private:
	Brain *_brain;
};

#endif