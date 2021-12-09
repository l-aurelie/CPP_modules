#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {}

		virtual void learnMateria(AMateria* materia)					= 0;
		virtual AMateria *createMateria(const std::string &type)		= 0;
};

#endif

