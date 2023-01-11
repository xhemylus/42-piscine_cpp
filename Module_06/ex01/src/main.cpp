#include "serialisation.hpp"

int main(void)
{
	Serialisation serialisation;
	Data *data = new Data;
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";
	std::cout << "data->s1 = " << data->s1 << std::endl;
	std::cout << "data->n = " << data->n << std::endl;
	std::cout << "data->s2 = " << data->s2 << std::endl;
	uintptr_t raw = serialisation.serialize(data);
	Data *data2 = serialisation.deserialize(raw);
	std::cout << "data2->s1 = " << data2->s1 << std::endl;
	std::cout << "data2->n = " << data2->n << std::endl;
	std::cout << "data2->s2 = " << data2->s2 << std::endl;
	delete data;
	//delete data2;
	return (0);
}