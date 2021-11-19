#include "Zombie.hpp"

Zombie::Zombie(const std::string &name): _name(name)
{

}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
