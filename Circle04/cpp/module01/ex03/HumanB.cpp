#include "HumanB.hpp"

void	HumanB::attack( void ) {
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << _weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon = &weapon;
}

HumanB::HumanB( std::string name ) : _name(name) {
	std::cout << "HumanB Constructor is called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB Destructor is called" << std::endl;
}
