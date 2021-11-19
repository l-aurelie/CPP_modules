#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap harry("Harry Potter");
	ScavTrap drago("Drago Malefoy");

	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	harry.beRepaired(25);
	drago.beRepaired(25);
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.guardGate();
	return 0;
}
