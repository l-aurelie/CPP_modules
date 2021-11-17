#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat(void);
	WrongCat(const WrongCat &src);
	~WrongCat(void);
	
	WrongCat &operator=(const WrongCat &rhs);

	virtual void	makeSound(void) const;
};

#endif
