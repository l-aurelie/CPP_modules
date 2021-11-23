#include "Dog.hpp"


Dog::Dog(void): AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constructor" << std::endl;
}
Dog::Dog(const Dog &src): AAnimal(src), _brain(new Brain())
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
	AAnimal::operator=(rhs);
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
