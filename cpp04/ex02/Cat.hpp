#ifndef CAT_HPP 
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
	Cat(void);
	Cat(const Cat &src);
	~Cat(void);
	
	Cat &operator=(const Cat &rhs);

	virtual void	makeSound(void) const;
	Brain *getBrain();

	private:
	Brain * _brain;
};

#endif
