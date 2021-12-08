#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Constructor, default" << std::endl;
	this->_hitpoint = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "FragTrap Constructor, init name" << std::endl;
	this->_hitpoint = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "FragTrap Constructor, copy" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}


/***********************************************************/

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	ClapTrap::operator=(rhs);	
	std::cout << " FragTrap Assignation" << std::endl;
	return *this;
}


/***********************************************************/


void FragTrap::highFivesGuys(void)
{
	std::cout << "Gimme five guys !" << std::endl;
}
