#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "wronganimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	void makeSound(void)const;
};

#endif