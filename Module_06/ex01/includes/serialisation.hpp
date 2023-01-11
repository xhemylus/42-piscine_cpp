#ifndef SERIALISATION_HPP
#define SERIALISATION_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string s1;
	int n;
	std::string s2;
} Data;

class Serialisation
{
public:
	Serialisation();
	Serialisation(const Serialisation &src);

	~Serialisation();

	Serialisation &operator=(const Serialisation &src);
	
	uintptr_t serialize(Data* ptr);
	Data *deserialize(uintptr_t raw);
};

#endif