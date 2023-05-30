#include "Zombie.hpp"

Zombie*	Zombie::newZombie( std::string name ) {
	Zombie*	ptr;

	ptr = new Zombie;
	ptr->setZombieName(name);
	return (ptr);
}
