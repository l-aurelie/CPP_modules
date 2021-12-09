#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) { *this = src; }

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4 && _source[i]; i++)
		delete _source[i];
}

/*************************************************/

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4 && _source[i]; i++)
		delete _source[i];
	for (int i = 0; i < 4; i++)
		if (rhs._source[i])
			_source[i] = rhs._source[i]->clone();
	return (*this);
}


/*************************************************/

void MateriaSource::printSource(void) const
{
	std::cout << "(" << _source << ")" << std::endl;
	for (int i = 0; i < 4 && _source[i]; i++)
		std::cout <<"Source " << i << ": " << _source[i]->getType() << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia) {
	int i;

	for (i = 0; i < 4 && _source[i]; i++)
		;
	if (i >= 4)
		return;
	_source[i] = materia;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_source[i] && _source[i]->getType() == type)
			return (_source[i]->clone());
	}
	return (NULL);
}
