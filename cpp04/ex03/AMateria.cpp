
#include "AMateria.hpp"

AMateria::AMateria(void) : type("UnknowMateria") {}

AMateria::AMateria(const AMateria &src) { *this = src; }

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::~AMateria(void) {}


/*************************************************/

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this == &rhs)
		return (*this);
	type = rhs.type;
	return (*this);
}


/*************************************************/

const std::string &AMateria::getType(void) const
{
	return (type);
}

void AMateria::use(ICharacter &target) const
{
	std::cout << "Using unknown Materia on " << target.getName() << std::endl;
}
