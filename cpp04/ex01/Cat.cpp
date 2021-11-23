#include "Cat.hpp"


Cat::Cat(void): Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructor" << std::endl;
}
Cat::Cat(const Cat &src): Animal(src), _brain(new Brain())
{
	std::cout << "Cat constructor copy" << std::endl;
	*this = src;
}
Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructor " << std::endl;
}


/*****************************************************/

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Assignation" << std::endl;
	if (this == &rhs)
		return (*this);
	Animal::operator=(rhs);
	*this->_brain = *rhs._brain;
	return (*this);
}

/*****************************************************/

Brain *Cat::getBrain()
{
	return (this->_brain);
}


/*****************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "MIAOUUUUUU" << std::endl;
}
