#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("")
{
	std::cout << "WrongAnimal constructor default" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string &type): _type(type)
{
	std::cout << "WrongAnimal constructor type" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal constructor copy" << std::endl;
	*this = src;
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor " << std::endl;
}

/*****************************************************/


WrongAnimal & WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "Assignation" << std::endl;
	this->_type = rhs._type;
	return (*this);
}


/*****************************************************/

void	WrongAnimal::makeSound(void) const
{
	std::cout << "I'm an WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
