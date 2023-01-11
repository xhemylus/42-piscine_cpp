#ifndef ICE_HPP
#define ICE_HPP

#include <aMateria.hpp>
#include <ICharacter.hpp>

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice & src);

	void use(ICharacter& target);
}
#endif