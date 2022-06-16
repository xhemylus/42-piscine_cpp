#include "polymorphisme.hpp"

int main()
{
	const Animal* Meta = new Animal();
	std::cout << "Type : " << Meta->getType() << " " << std::endl;
	Meta->makeSound();
	delete Meta;

	std::cout << "--------------------" << std::endl;

	const Animal* Doggo = new Dog();
	std::cout << "Type : " << Doggo->getType() << " " << std::endl;
	Doggo->makeSound();
	delete Doggo;

	std::cout << "--------------------" << std::endl;

	const Animal* Catto = new Cat();
	std::cout << "Type : " << Catto->getType() << " " << std::endl;
	Catto->makeSound();
	delete Catto;

	std::cout << "--------------------" << std::endl;

	const WrongAnimal* W_Meta = new WrongAnimal();
	std::cout << "Type : " << W_Meta->getType() << " " << std::endl;
	W_Meta->makeSound();
	delete W_Meta;

	std::cout << "--------------------" << std::endl;

	const WrongAnimal* W_Catto = new WrongCat();
	std::cout << "Type : " << W_Catto->getType() << " " << std::endl;
	W_Catto->makeSound();
	delete W_Catto;

}