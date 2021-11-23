#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
	Dog(void);
	Dog(const Dog &src);
	~Dog(void);
	
	Dog &operator=(const Dog &rhs);

	virtual void	makeSound(void) const;
	Brain *getBrain();

	private:
	Brain * _brain;
};

#endif
