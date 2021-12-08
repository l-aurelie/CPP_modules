#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &src);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &rhs);
	
	using ScavTrap::attack;
	void whoAmI() const;
	void printDiamond() const;
	
private:
	std::string _name;
};

#endif
