#include "polymorphisme.hpp"

int main()
{
	const Animal *meta[10];

	std::cout << "BUILDING" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}

	std::cout << "TESTING" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal Type : " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++)
		delete(meta[i]);

	std::cout << "Deep Copy" << std::endl;

	Dog *a = new Dog();
	a->setIdea(0, "Bonjour je suis un Doggo");
	a->setIdea(101, "TEST");

	Dog *b = new Dog(*a);

	std::cout << "TESTING" << std::endl;

	a->getIdeas();
	std::cout << std::endl;

	b->getIdeas();
	std::cout << std::endl;
	delete(a);
	delete(b);
}