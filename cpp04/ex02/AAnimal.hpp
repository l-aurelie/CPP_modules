#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal{
	public:
	AAnimal(void);
	AAnimal(const std::string &type);
	AAnimal(const AAnimal &src);
	virtual ~AAnimal(void);
	
	AAnimal &operator=(const AAnimal &rhs);

	virtual void	makeSound(void) const = 0;
	std::string getType(void) const;
	protected:
	std::string _type;

};

#endif
