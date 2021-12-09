#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
public:
	Cure(void);
	Cure(const Cure &src);
	virtual ~Cure(void);

	Cure &operator=(const Cure &rhs);

	AMateria *clone(void) const;
	void use(ICharacter &target) const;
};

#endif

