#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), _name("default")
{
	std::cout << "DiamondTrap Constructor, default" << std::endl;
	ClapTrap::_name += "_clap_name";
	ScavTrap::setInitialEnergy();
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor, init name" << std::endl;
	ClapTrap::_name += "_clap_name";
	ScavTrap::setInitialEnergy();
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)

{
	std::cout << "DiamondTrap Constructor, copy" << std::endl;
	ClapTrap::_name += "_clap_name";
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}


/***********************************************************/

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << " DiamondTrap Assignation" << std::endl;
	this->_name = rhs._name;
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_hitpoint = rhs._hitpoint;
	this->_energy_point = rhs._energy_point;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}


/***********************************************************/

void DiamondTrap::whoAmI() const
{
	std::cout << "clap_name = " << this->ClapTrap::_name << std::endl;
	std::cout << "diamond_name = " << this->_name << std::endl;
}

void DiamondTrap::printDiamond() const
{
	std::cout << "-- " << this->_name << " ; " << ClapTrap::_name << "  " << this->_hitpoint << "  " << this->_energy_point << "  " << this->_attack_damage << std::endl; 
}
