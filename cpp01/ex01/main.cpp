#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	if (!(zombie = zombieHorde(12, "membre")))
		return 1;
	for (int i = 0; i < 12; i++)
	{
		zombie[i].announce();
	}

	delete []zombie;
}
