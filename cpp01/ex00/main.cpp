#include "Zombie.hpp"

int main()
{
	Zombie gil("Gil");
	gil.announce();
	Zombie *marta;

	randomChump("elvin");
	marta = newZombie("Marta");
	marta->announce();
	Zombie marc("marc");
	marc.announce();
	delete marta;
	return 0;
}
