#include "Weapon.hpp"

Weapon::Weapon(const std::string &type): _type(type)
{}

Weapon::Weapon(void): _type("default")
{}

Weapon::~Weapon(void)
{}

std::string Weapon::getType(void) const
{
	return(this->_type);
}

void Weapon::setType(const std::string &new_type)
{
	this->_type = new_type; 
}
