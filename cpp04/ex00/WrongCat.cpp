#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	std::cout << "WrongCat constructor copy" << std::endl;
	*this = src;
}
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor " << std::endl;
}

/*****************************************************/


WrongCat & WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "Assignation" << std::endl;
	WrongAnimal::operator=(rhs);
	return (*this);
}


/*****************************************************/

void	WrongCat::makeSound(void) const
{
	std::cout << "MIAOUUU" << std::endl;
}
