#include "ClapTrap.hpp"

int main()
{
	ClapTrap harry("Harry Potter");
	ClapTrap drago("Drago Malefoy");

	drago.boost();	
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
	return 0;
}
