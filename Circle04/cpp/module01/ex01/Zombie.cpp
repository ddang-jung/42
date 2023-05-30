#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

void	Zombie::setZombieName( std::string str ) {
	name = str;
}

Zombie::Zombie() : name("") {
	std::cout << "Constructor is called" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << "'s Destructor is called" << std::endl;
}