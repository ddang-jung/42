#include "Zombie.hpp"

Zombie*	Zombie::newZombie( std::string str ) {
	Zombie*	ptr;

	ptr = new Zombie;
	ptr->setZombieName(str);
	return (ptr);
}
