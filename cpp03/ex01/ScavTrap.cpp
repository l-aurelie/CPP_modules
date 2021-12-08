#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Constructor, default" << std::endl;
	this->_hitpoint = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "ScavTrap Constructor, init name" << std::endl;
	this->_hitpoint = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap Constructor, copy" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}


/***********************************************************/

ScavTrap & ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	ClapTrap::operator=(rhs);	
	std::cout << " ScavTrap Assignation" << std::endl;
	return *this;
}


/***********************************************************/

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap : ";
	ClapTrap::attack(target);
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << this->_name << " have entered gate keeper mode" << std::endl; 
}
