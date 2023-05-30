#include "Zombie.hpp"

int	main(void) {
	Zombie	a;
	Zombie	*ptr;

	// STACK in main
	a.setZombieName("A");
	a.announce();

	// HEAP
	ptr = a.newZombie("B");
	ptr->announce();
	delete(ptr);

	// STACK in randomChump
	a.randomChump("C");

	return (0);
}