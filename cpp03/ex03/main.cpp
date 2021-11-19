#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap harry("Potter");
	DiamondTrap drago("Malefoy");

	std::cout << "-- claptrap ; claptrap_clap_name 10   10  0" << std::endl;
	std::cout << "-- scavtrap ; scavtrap_clap_name 100  50  20" << std::endl;
	std::cout << "-- fragtrap ; fragtrap_clap_name 100  100 30" << std::endl;
	harry.printDiamond();
	std::cout << std::endl;
	
	DiamondTrap james(harry);
	james.printDiamond();
	std::cout << std::endl;

	DiamondTrap lucius = drago;;
	lucius.printDiamond();
	std::cout << std::endl;

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
	std::cout << std::endl;
	
	harry.guardGate();
	harry.highFivesGuys();
	harry.whoAmI();
	return 0;
}
