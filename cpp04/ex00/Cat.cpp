#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat constructor" << std::endl;
}
Cat::Cat(const Cat &src)
{
	std::cout << "Cat constructor copy" << std::endl;
	*this = src;
}
Cat::~Cat(void)
{
	std::cout << "Cat destructor " << std::endl;
}

/*****************************************************/


Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Assignation" << std::endl;
	Animal::operator=(rhs);
	return (*this);
}


/*****************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "MIAOUUU" << std::endl;
}
