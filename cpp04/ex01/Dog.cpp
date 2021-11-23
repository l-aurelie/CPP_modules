#include "Dog.hpp"


Dog::Dog(void): Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constructor" << std::endl;
}
Dog::Dog(const Dog &src): Animal(src), _brain(new Brain())
{
	std::cout << "Dog constructor copy" << std::endl;
	*this = src;
}
Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor " << std::endl;
}


/*****************************************************/

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Assignation" << std::endl;
	if (this == &rhs)
		return (*this);
	Animal::operator=(rhs);
	*this->_brain = *rhs._brain;
	return (*this);
}

/*****************************************************/

Brain *Dog::getBrain()
{
	return (this->_brain);
}


/*****************************************************/

void	Dog::makeSound(void) const
{
	std::cout << "OUAFFFFF" << std::endl;
}
