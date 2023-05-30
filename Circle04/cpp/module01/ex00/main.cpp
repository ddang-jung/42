#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie;
	Zombie	*ptr;

	// STACK in main
	zombie.setZombieName("A");
	zombie.announce();

	// HEAP
	ptr = zombie.newZombie("B");
	ptr->announce();
	delete(ptr);

	// STACK in randomChump
	zombie.randomChump("C");

	return (0);
}