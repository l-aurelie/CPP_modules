#include "Animal.hpp"

Animal::Animal(void): _type("")
{
	std::cout << "Animal constructor default" << std::endl;
}
Animal::Animal(const std::string &type): _type(type)
{
	std::cout << "Animal constructor type" << std::endl;
}
Animal::Animal(const Animal &src)
{
	std::cout << "Animal constructor copy" << std::endl;
	*this = src;
}
Animal::~Animal(void)
{
	std::cout << "Animal destructor " << std::endl;
}

/*****************************************************/


Animal & Animal::operator=(const Animal &rhs)
{
	std::cout << "Assignation" << std::endl;
	this->_type = rhs._type;
	return (*this);
}


/*****************************************************/

void	Animal::makeSound(void) const
{
	std::cout << "I'm an Animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
