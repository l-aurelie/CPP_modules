#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog constructor" << std::endl;
}
Dog::Dog(const Dog &src)
{
	std::cout << "Dog constructor copy" << std::endl;
	*this = src;
}
Dog::~Dog(void)
{
	std::cout << "Dog destructor " << std::endl;
}

/*****************************************************/


Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Assignation" << std::endl;
	Animal::operator=(rhs);
	return (*this);
}


/*****************************************************/

void	Dog::makeSound(void) const
{
	std::cout << "OUAFFFFF" << std::endl;
}
