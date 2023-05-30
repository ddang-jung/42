#include "Zombie.hpp"

void	Zombie::randomChump( std::string name ) {
	Zombie	random;

	random.setZombieName(name);
	random.announce();
}