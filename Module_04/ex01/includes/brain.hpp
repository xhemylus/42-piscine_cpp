#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain & src);

	Brain & operator=(const Brain & src);
	void setIdea(unsigned int i, std::string idea);
	std::string getIdea(unsigned int i);
private:
	std::string _ideas[100];
};

#endif