#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat & src);
	void makeSound(void)const;
	void getIdeas(void)const;
	void setIdea(unsigned int i, std::string idea);

	Cat & operator=(const Cat & src);
private:
	Brain *_brain;
};

#endif