#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog & src);
	void makeSound(void)const;
	void getIdeas(void)const;
	void setIdea(unsigned int i, std::string idea);


	Dog & operator=(const Dog & src);
private:
	Brain *_brain;
};

#endif