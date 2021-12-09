#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
	Ice(void);
	Ice(const Ice &src);
	virtual ~Ice(void);

	Ice &operator=(const Ice &rhs);

	AMateria *clone(void) const;
	void use(ICharacter &target) const;
};

#endif
