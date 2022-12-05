#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "wronganimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat & src);
	void makeSound(void)const;

	WrongCat & operator=(const WrongCat & src);
};

#endif