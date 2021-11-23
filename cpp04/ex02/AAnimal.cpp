#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("")
{
	std::cout << "AAnimal constructor default" << std::endl;
}
AAnimal::AAnimal(const std::string &type): _type(type)
{
	std::cout << "AAnimal constructor type" << std::endl;
}
AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal constructor copy" << std::endl;
	*this = src;
}
AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor " << std::endl;
}

/*****************************************************/


AAnimal & AAnimal::operator=(const AAnimal &rhs)
{
	std::cout << "Assignation" << std::endl;
	this->_type = rhs._type;
	return (*this);
}


/*****************************************************/

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
