#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal & src);
	virtual void makeSound(void)const;
	std::string getType(void)const;

	Animal & operator=(const Animal & src);

protected:
	std::string _type;

};

#endif