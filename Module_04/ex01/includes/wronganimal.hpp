#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	virtual void makeSound(void)const;
	std::string getType(void)const;

protected:
	std::string _type;

};

#endif