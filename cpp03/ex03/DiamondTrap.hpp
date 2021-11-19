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
	DiamondTrap(DiamondTrap const &src);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &rhs);
	
	using ScavTrap::attack;
	void whoAmI() const;
	void printDiamond() const;
	
private:
	std::string _name;
};

#endif
