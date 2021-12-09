#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character: public ICharacter {
public:
	Character(void);
	Character(const Character &src);
	Character(const std::string &name);
	virtual ~Character(void);

	Character &operator=(const Character &rhs);

	const std::string &getName(void) const;
	void printInventory(void) const;
	void equip(AMateria *materia);
	void unequip(int index);
	void use(int index, ICharacter &target);

private:
	std::string _name;
	AMateria *_inventory[4];
	int _slot;
};

#endif
