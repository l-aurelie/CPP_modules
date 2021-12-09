#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria(src) { *this = src; }

Cure::~Cure(void) {}


/**************************************************/

Cure &Cure::operator=(const Cure &rhs)
{
	if (this == &rhs)
		return (*this);
	AMateria::operator=(rhs);
	return (*this);
}


/**************************************************/

AMateria *Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
