#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): _name(name), _weapon(NULL)
{}

HumanB::~HumanB(void)
{}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (_weapon)
		std::cout << this->_name << " attacks with his " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack without weapon" << std::endl;
}
