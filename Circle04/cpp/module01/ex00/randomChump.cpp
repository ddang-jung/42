#include "Zombie.hpp"

void	Zombie::randomChump( std::string str ) {
	Zombie	random;

	random.setZombieName(str);
	random.announce();
}