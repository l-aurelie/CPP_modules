
#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src) { *this = src; }

Ice::~Ice(void) {}


/************************************************************/

// TODO: copie type ?
Ice& Ice::operator=(const Ice &rhs)
{
	if (this == &rhs)
		return (*this);
	AMateria::operator=(rhs);
	return (*this);
}


/************************************************************/

// TODO: risque LEAKS ?
AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
