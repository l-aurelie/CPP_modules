#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap harry("Harry Potter");
	FragTrap drago("Drago Malefoy");

	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	harry.beRepaired(50);
	drago.beRepaired(25);
	drago.attack("Harry Potter");
	harry.takeDamage(drago.getDamage());
	drago.attack("Harry Potter");
	harry.highFivesGuys();
	return 0;
}
