#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, const std::string &name)
{
	Zombie *zombies;
	std::stringstream ss;
	std::string indice;
 
	if(N < 1)
		return NULL;
	zombies = new Zombie[N];	
	for(int i = 0; i < N; i++)
	{
		ss << i;
		indice = ss.str();
		zombies[i].setName(name + indice);
		ss.str("");	
	}
	return zombies;
}
