#ifndef AAMATERIA_HPP
#define AAMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {
public:
		AMateria(void);
		AMateria(const AMateria &src);
		AMateria(const std::string &type);
		virtual ~AMateria(void);

		AMateria &operator=(const AMateria &rhs);

		const std::string &getType(void) const;
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target) const;

protected:
		std::string type;
};

#endif

