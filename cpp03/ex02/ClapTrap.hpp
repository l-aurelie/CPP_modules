#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap{
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int getDamage()const;
	void boost();

protected:
	std::string _name;
	int _hitpoint;
	int _energy_point;
	int _attack_damage;
};

#endif
