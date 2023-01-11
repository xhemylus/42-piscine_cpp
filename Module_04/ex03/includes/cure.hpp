#ifndef CURE_HPP
#define CURE_HPP

#include <aMateria.hpp>
#include <ICharacter.hpp>

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure & src);

	void use(ICharacter& target);
}
#endif