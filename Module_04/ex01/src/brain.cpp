#include "brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain & Brain::operator=(const Brain & src)
{
	for (int i = 0; i < 100; i++)
	{
		if (src._ideas[i].length() > 0)
			this->_ideas[i].assign(src._ideas[i]);
	}
	return *this;
}

void Brain::setIdea(unsigned int i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "A brain can only contain 100 ideas." << std::endl;
		
}

std::string Brain::getIdea(unsigned int i)
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return("A brain can only contain 100 ideas.");
}