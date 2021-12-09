#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &src);
	virtual ~MateriaSource(void);

	MateriaSource& operator=(const MateriaSource &rhs);

	void printSource(void) const;
	void learnMateria(AMateria *materia);
	AMateria* createMateria(const std::string &type);

private:
	AMateria* _source[4];
};

#endif

