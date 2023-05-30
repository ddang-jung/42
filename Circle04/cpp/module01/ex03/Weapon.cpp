#include "Weapon.hpp"

const std::string	&Weapon::getType( void ) {
	return (type);
}

void	Weapon::setType( std::string newType ) {
	type = newType;
}

Weapon::Weapon( std::string str ) : type(str) {
	std::cout << "Weapon Constructor is called" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon Destructor is called" << std::endl;
}
