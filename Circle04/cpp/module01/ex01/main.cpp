#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie;
	Zombie	*horde;
	int		N;

	zombie.setZombieName("Z");
	zombie.announce();
	N = 100;
	horde = zombie.zombieHorde(N, "H");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}