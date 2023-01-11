#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat & src);
	void makeSound(void)const;

	Cat & operator=(const Cat & src);
};

#endif