#include "ClapTrap.hpp"


ClapTrap::ClapTrap(): _name("default"), _hitpoint(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "Constructor, default" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitpoint(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "Constructor, init name" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Constructor, copy" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor" << std::endl;
}

/***********************************************************/

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Assignation" << std::endl;
	this->_name = rhs._name;
	this->_hitpoint = rhs._hitpoint;
	this->_energy_point = rhs._energy_point;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}

/***********************************************************/


void ClapTrap::attack(const std::string &target)
{
	if (this->_energy_point <= 0)
	{
		std::cout << this->_name << " has no more energy left to attack" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks on " << target << std::endl;
	this->_energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		return ;
	this->_hitpoint -= amount;
	if(this->_hitpoint <= 0)
	{
		this->_hitpoint = 0;
		std::cout << this->_name << " IS DEAD" << std::endl;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " damages and has " << this->_hitpoint << " life points left" << std::endl;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount <= 0)
		return;
	if(this->_hitpoint == 0)
		std::cout << this->_name << " is back to life with " << this->_hitpoint + amount << " life points" << std::endl;
	else
		std::cout << this->_name << " repaired and has now " << this->_hitpoint + amount << " life points and regain +5 energy "<< std::endl;
	this->_hitpoint += amount;
	this->_energy_point += 5;
}

int ClapTrap::getDamage()const
{
	return(this->_attack_damage);
}

void ClapTrap::boost()
{
	std::cout << this->_name << " take a potion booster and gain two more attack damage!" << std::endl;
	this->_attack_damage += 2;
}
