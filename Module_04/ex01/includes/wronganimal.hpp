#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal & src);
	virtual void makeSound(void)const;
	std::string getType(void)const;

	WrongAnimal & operator=(const WrongAnimal & src);

protected:
	std::string _type;

};

#endif