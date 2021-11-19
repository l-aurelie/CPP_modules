#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
public:
	Weapon(void);
	Weapon(const std::string &_type);
	~Weapon(void);
	std::string getType(void) const;
	void setType(const std::string &_type);

private:
	std::string _type;
};
#endif
