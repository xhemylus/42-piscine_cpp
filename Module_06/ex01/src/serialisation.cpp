#include "serialisation.hpp"

Serialisation::Serialisation()
{
	std::cout << "Serialisation constructor called" << std::endl;
}

Serialisation::Serialisation(const Serialisation &src)
{
	std::cout << "Serialisation copy constructor called" << std::endl;
	*this = src;
}

Serialisation::~Serialisation()
{
	std::cout << "Serialisation destructor called" << std::endl;
}

Serialisation &Serialisation::operator=(const Serialisation &src)
{
	std::cout << "Serialisation assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t Serialisation::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialisation::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
