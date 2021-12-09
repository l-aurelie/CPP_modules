
#include "Character.hpp"

Character::Character(void) : _name("Unnamed"), _slot(0) {}

Character::Character(const Character &src) { *this = src; }

Character::Character(const std::string &name) : _name(name), _slot(0) {}

Character::~Character(void)
{
	for (int i = 0; i < _slot; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}


/************************************************************/

Character &Character::operator=(const Character &rhs)
{
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	for (int i = 0; i < _slot; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	_slot = rhs._slot;
	for (int i = 0; i < _slot; i++)
		_inventory[i] = rhs._inventory[i]->clone();
	return (*this);
}


/************************************************************/

const std::string &Character::getName(void) const
{
	return (_name);
}

void Character::printInventory(void) const
{
	std::cout << "(" << _inventory << ")" << std::endl;
	for (int i = 0; i < _slot; i++)
	{
		if (_inventory[i])
			std::cout <<"Inventory " << i << ": " << _inventory[i]->getType() << std::endl;
		else
			std::cout << _inventory[i] << std::endl;
	}
}

void Character::equip(AMateria *materia)
{
	if (_slot >= 4)
		return;
	_inventory[_slot] = materia;
	_slot += 1;
}

void Character::unequip(int index)
{
	if (index >= _slot || index < 0)
		return;
	_inventory[index] = NULL;
	if (index == _slot)
		_slot -= 1;
}

void Character::use(int index, ICharacter &target)
{
	if (index >= _slot || index < 0 || !_inventory[index])
		return;
	_inventory[index]->use(target);
}
