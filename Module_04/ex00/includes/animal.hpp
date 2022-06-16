#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	virtual void makeSound(void)const;
	std::string getType(void)const;

protected:
	std::string _type;

};

#endif